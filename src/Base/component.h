//
// Created by f2561 on 24-5-9.
//

#ifndef AIRLIFE_COMPONENT_H
#define AIRLIFE_COMPONENT_H

#include <cstddef>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <unordered_map>
#include "../Core/LoginHandler.h"
#define UShortLen sizeof(UShort)
namespace COMPONENT {

    typedef unsigned short UShort;

    class User;
    class Airplane;
    class Orders;
    class Chargebacks;
    class Flight;
    class Area;
    class Account;
    /* 注册全局表 */
    static std::unordered_map<std::string, Area*> areaRegistry;
    static std::unordered_map<std::string, Airplane*> airplaneRegistry;
    static std::unordered_map<std::string, Flight*> flightRegistry;
    static std::unordered_map<std::string, User*> userRegistry;
    static std::unordered_map<std::string, Orders*> orderRegistry;
    static std::unordered_map<std::string, Chargebacks*> chargebacksRegistry;
    class Date {
    public:
        Date();
        class Time {
        private:
            UShort Hour;
            UShort Minute;
            Time(UShort Hour, UShort Minute);

        public:
            Time() = default;
            static Time *getTime(UShort Hour, UShort Minute);
            std::string toString() const;
            void setTime(const Date::Time& _time);
            UShort getHour() const;
            UShort getMinute() const;
            ~Time();
            std::vector<char> serialize() const;
            static Date::Time deserialize(const std::vector<char>& data);
        };
        ~Date();
    private:
        UShort Year{};
        UShort Month{};
        UShort Day{};
        Time time{};
        static UShort getMonthDay(UShort Year, UShort Month);
        Date(UShort Year, UShort Month, UShort Day, const Time& time);
    public:
        static Date *getDate(UShort Year, UShort Month, UShort Day, const Time& time);
        UShort getYear() const;
        UShort getMonth() const;
        UShort getDay() const;
        Time getTime() const;
        std::string toString();
        std::vector<char> serialize() const;
        static Date deserialize(const std::vector<char>& data);
    };
    class Area {
        std::string AreaName;
        std::string UUID;
    public:
        explicit Area(std::string areaName);
        Area();
        std::string toString();
        static void registerArea(Area* area);
        bool initAreaNameOnce(const std::string& Name);
        bool tryModifyName(const std::string& newName);
        std::vector<char> serialize() const;
        static Area* deserialize(const std::vector<char>& data);
    };
    class Airplane {
        std::string UUID;
        UShort Capacity{};
        UShort CurrentNumber{};
    public:
        Airplane();
        Airplane(std::string uuid, UShort capacity);
        bool initUUIDAndCapacityOnce(const std::string& uuid, UShort capacity);
        std::string getUUID();
        static void registerAirplane(Airplane* airplane);
        UShort getCapacity() const;
        UShort getCurrentNumber() const;
        bool tryModifyCapacity(int NewCapacityValue);
        bool tryChangeCurrentNumber(int delta);
        bool isFull() const;
        std::vector<char> serialize() const;
        static Airplane* deserialize(const std::vector<char>& data);

    };
    class Flight {
        std::string UUID;
        Airplane *Airplane{};
        Area *StartingPoint{},*Destination{};
        Date DepartureTime;
        Date::Time TakeTime{};
        bool hadInit;
    public:
        explicit Flight(std::string UUID);

        Flight();
        static void registerFlight(Flight* flight);
        std::string getUUID();
        class Airplane* getAirplane();
        Area* getStartingPointArea();
        Area* getDestinationArea();
        Date getDepartureTime();
        Date::Time getTakeTime();
        bool initUUID(std::string uuid);
        bool initValueOnce(class Airplane& airplane, Area& startingPoint,  Area& destination, const Date& departureTime, const Date::Time& takeTime);
        bool tryModifyAirplane(class Airplane& newAirplane);
        bool tryChangeStartPointArea(Area& area);
        bool tryChangeDestinationArea(Area& area);
        bool tryModifyDepartureDate(const Date& date);
        bool tryModifyTakeTime(const Date::Time& time);
        std::vector<char> serialize() const;
        static Flight* deserialize(const std::vector<char>& data);

    };
    class User {
        std::string Name;
        std::string UUID;
        std::vector<Orders*> OrderList;//动态数组
        std::vector<Chargebacks*> ChargeBackList;
    public:
        explicit User(std::string uuid);
        static void registerUser(User* user);
        User();

        std::string getName();
        std::string getUUID();
        std::vector<Orders*> getOrderList();
        std::vector<Chargebacks*> getChargeBackList();
        static User* getUserByUUID(const std::string& uuid);
        bool initUUID(std::string uuid);
        bool tryChangeName(const std::string& name);

        std::vector<char> serialize() const;
        static User* deserialize(const std::vector<char> &data);
    };
    class Orders {
        std::string OwnerUUID{};
        User* Owner{};
        Date OrderCreatedDate;
        Flight* TargetFlight{};
        std::string OrderUUID;
        bool Valid{};//有效
    protected:
        Orders(User* o, const Date& oD, Flight* tF, const std::string& oU);
        Orders(std::string  ownerUUID, const Date& oD,Flight* tF, const std::string& oU);
    public:
        Orders();
        static void registerOrder(Orders* order);
        static Orders* CreateOrder(User& owner, const Date& orderCreateDate, Flight& targetFlight, const std::string& orderUUID);
        static void enable(Orders od);
        static void disable(Orders od);
        User* getUser();
        Date getOrderCreatedDate();
        Flight* getTargetFlight();
        std::string getOrderUUID();
        bool isValid() const;
        // 序列化方法/反序列化方法
        std::vector<char> serialize() const;
        static Orders* deserialize(const std::vector<char>& data, size_t& offset);
        static Orders* deserialize(const std::vector<char>& data) {size_t initOffset = 0; return Orders::deserialize(data, initOffset);};

    };
    class Chargebacks {
        std::string OwnerUUID;
        User* Owner{};
        Date ChargebackCreateDate;
        std::string ChargebackUUID;
        Orders* TargetOrder{};
        bool Successful{};//是否成功
    protected:
        Chargebacks(User* o, const Date& oD,Orders* os, std::string cU);
        Chargebacks(std::string  ownerUUID, const Date &oD, Orders* os, const std::string& cU);
    public:
        Chargebacks();
        static void registerChargeback(Chargebacks* chargebacks);
        User* getUser();
        Date getChargebackCreatedDate();
        std::string getChargebackUUID();
        Orders* getTargetOrder();
        bool isSuccessful() const;
        void enable();
        std::vector<char> serialize() const;
        static Chargebacks* deserialize(const std::vector<char>& data, size_t& offset);
        static Chargebacks* deserialize(const std::vector<char>& data) { size_t initOffset = 0;return Chargebacks::deserialize(data, initOffset); }
    };
    class Account {
        airLifeHandler::AccountType AccountType;
        struct Inf{
            Inf() = default;
            User* AccountUser{};
            std::string AdministerUUID;
            explicit Inf(User* user) : AccountUser(user) {}
            explicit Inf(std::string uuid)
                    : AdministerUUID(std::move(uuid)), AccountUser(nullptr) {}
            ~Inf() = default; // Destructor for union
        }inf;
        bool isValid;
    public:
        Account(airLifeHandler::AccountType accountType ,const std::string& uuid);
        Account(airLifeHandler::AccountType accountType, User& user);
        std::vector<char> serialize() const;
        static Account* deserialize(const std::vector<char>& data);
    };

    static size_t
    AreaBlockSize = sizeof(Area),
    AirplaneBlockSize = sizeof(Airplane),
    FlightBlockSize = sizeof(Flight),
    OrderBlockSize = sizeof(Orders),
    ChargebacksBlockSize = sizeof(Chargebacks),
    UserBlockSize = sizeof(User),
    AccountBlockSize = sizeof(Account);

} // COMPONENT
namespace airLifeHandler {
    enum DataType{
        USER,
        AIRPLANE,
        ORDER,
        CHARGEBACK,
        FLIGHT,
        AREA,
        ACCOUNT,
        DATE,
        TIME,
        UNKNOWN_DATA_TYPE
    };
    enum ResultStatus {
        INITIAL,
        INITIAL_FAILED,
        WAITING,
        RUNNING,
        SUCCESSFUL,
        FAILED
    };
}

#endif //AIRLIFE_COMPONENT_H
