//
// Created by f2561 on 24-5-9.
//

#ifndef AIRLIFE_COMPONENT_H
#define AIRLIFE_COMPONENT_H

#include <cstddef>
#include <exception>
#include <iostream>
#include <vector>
#include "../Core/LoginHandler.h"

namespace COMPONENT {

    typedef unsigned short UShort;
    class User;
    class Airplane;
    class Orders;
    class Chargebacks;
    class Flight;
    class Area;
    class Account;
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
    };
    class Area {
        std::string AreaName;
    public:
        explicit Area(std::string areaName);
        Area();
        std::string toString();
        bool initAreaNameOnce(const std::string& Name);
        bool tryModifyName(const std::string& newName);
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
        UShort getCapacity() const;
        UShort getCurrentNumber() const;
        bool tryModifyCapacity(int NewCapacityValue);
        bool tryChangeCurrentNumber(int delta);
        bool isFull() const;

    };
    class Flight {
        std::string UUID;
        Airplane Airplane;
        Area StartingPoint,Destination;
        Date DepartureTime;
        Date::Time TakeTime{};
        bool hadInit;
    public:
        explicit Flight(std::string UUID);

        Flight();

        std::string getUUID();
        class Airplane getAirplane();
        Area getStartingPointArea();
        Area getDestinationArea();
        Date getDepartureTime();
        Date::Time getTakeTime();
        bool initUUID(std::string uuid);
        bool initValueOnce(class Airplane airplane ,const Area& startingPoint, const Area& destination, const Date& departureTime, const Date::Time& takeTime);
        bool tryModifyAirplane(class Airplane newAirplane);
        bool tryChangeStartPointArea(Area area);
        bool tryChangeDestinationArea(Area area);
        bool tryModifyDepartureDate(const Date& date);
        bool tryModifyTakeTime(const Date::Time& time);

    };
    class User {
        std::string Name;
        std::string UUID;
        std::vector<Orders> OrderList;//动态数组
        std::vector<Chargebacks> ChargeBackList;
    public:
        explicit User(std::string uuid);

        User();

        std::string getName();
        std::string getUUID();
        std::vector<Orders> getOrderList();
        std::vector<Chargebacks> getChargeBackList();
        bool initUUID(std::string uuid);
        bool tryChangeName(const std::string& name);
    };
    class Orders {
        User Owner;
        Date OrderCreatedDate;
        Flight TargetFlight;
        std::string OrderUUID;
        bool Valid{};//有效
        Orders(User o, const Date& oD,const Flight& tF, const std::string& oU);
    public:
        static Orders* CreateOrder(User owner, const Date& orderCreateDate, const Flight& targetFlight, const std::string& orderUUID);
        static void enable(Orders od);
        static void disable(Orders od);
        User getUser();
        Date getOrderCreatedDate();
        Flight getTargetFlight();
        std::string getOrderUUID();
        bool isValid() const;
    };
    class Chargebacks {
        User Owner;
        Date ChargebackCreateDate;
        std::string ChargebackUUID;
        Orders TargetOrder;
        bool Successful;//是否成功
    public:
        User getUser();
        Date getChargebackCreatedDate();
        std::string getChargebackUUID();
        Orders getTargetOrder();
        bool isSuccessful();
        void enable();
    };
    class Account {
        airLifeHandler::AccountType AccountType;
        union {
            User _User;
            std::string AdministerUUID;
        };
    public:
        Account(airLifeHandler::AccountType accountType ,std::string uuid);

    };



} // COMPONENT

#endif //AIRLIFE_COMPONENT_H
