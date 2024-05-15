//
// Created by f2561 on 24-5-9.
//

#include "component.h"

#include <utility>

namespace COMPONENT {
    //Time Part method
    Date::Time::Time(COMPONENT::UShort Hour, COMPONENT::UShort Minute){
            this->Hour = Hour;
            this->Minute = Minute;
    }

    void Date::Time::setTime(const Date::Time& _time) {
        this->Minute = _time.Minute;
        this->Hour = _time.Hour;
    }
/**
 * 获得时间
 * @param Hour
 * @param Minute
 * @return *Time
 */
    Date::Time *Date::Time::getTime(COMPONENT::UShort Hour, COMPONENT::UShort Minute) {
        try{
            if(Hour >= 24 || Minute >= 60) throw std::exception();

        }catch (std::exception& e){
            std::cerr<<"Worry Data"<<std::endl;
        }
        return new Time(Hour, Minute);
    }
    UShort Date::Time::getHour() const {
        return Hour;
    }
    UShort Date::Time::getMinute() const {
        return Minute;
    }
    std::string Date::Time::toString() const{
        using std::string;
        using std::to_string;
        string hour,minute,toReturn;
        hour = to_string(Hour);
        minute = to_string(Minute);
        toReturn = hour + ":" + minute;
        return toReturn;
    }
    Date::Time::~Time() = default;
    //Date Part method
    Date::Date(COMPONENT::UShort Year, COMPONENT::UShort Month, COMPONENT::UShort Day, const COMPONENT::Date::Time &time)  {
        this->Year = Year;
        this->Month = Month;
        this->Day = Day;
        this->time = time;
    }
     UShort Date::getMonthDay(COMPONENT::UShort Year, COMPONENT::UShort Month) {
        int day[] = {30,0,31,30,31,30,31,31,30,31,30,31};
        if(Month != 2) return day[Month - 1];
        else if((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) return 29;
        else return 28;
    }
    /**
     * 获得Date对象
     * @param Year
     * @param Month
     * @param Day
     * @param time
     * @return *Data
     */
     Date * Date::getDate(COMPONENT::UShort Year, COMPONENT::UShort Month, COMPONENT::UShort Day, const COMPONENT::Date::Time& time) {
        try {
            if(Month > 12 || Day > getMonthDay(Year, Month)) throw std::exception();
        }catch(std::exception& e) {
            std::cerr<<"Worry Data"<<std::endl;
        }
        return new Date(Year, Month, Day, time);
    }
    /**
     * 格式化字符串输出
     * @return 格式化字符串
     */
    std::string Date::toString() {
        using std::string;
        using std::to_string;
        string year,month,day,Time,toReturn;
        year = to_string(Year);
        month = to_string(Month);
        day = to_string(Day);
        Time = time.toString();
        toReturn =  year + "/" + month + "/" + day + "-" + Time;
        return toReturn;
    }
    UShort Date::getYear() const {
        return Year;
    }
    UShort Date::getMonth() const {
        return Month;
    }
    UShort Date::getDay() const {
        return Day;
    }

    Date::Time Date::getTime() const {
        return time;
    }

    Date::~Date() = default;

    Date::Date() = default;

    Airplane::Airplane(std::string uuid, UShort capacity) :UUID(std::move(uuid)), Capacity(capacity){
        CurrentNumber = 0;
    }

    std::string Airplane::getUUID() {
        return UUID;
    }

    UShort Airplane::getCapacity() const {
        return Capacity;
    }

    UShort Airplane::getCurrentNumber() const {
        return CurrentNumber;
    }
    bool Airplane::isFull() const {
        return getCurrentNumber() == getCapacity();
    }
    bool Airplane::tryChangeCurrentNumber(int delta) {//更多失败情况待考虑
        if(CurrentNumber + delta < 0 || CurrentNumber + delta > Capacity || delta  >= USHRT_MAX) return false;
        CurrentNumber += delta;
        return true;
    }
/**
 *
 * @param NewCapacityValue 新值
 * @return 是否成功
 */
    bool Airplane::tryModifyCapacity(int NewCapacityValue) {
        if(NewCapacityValue <= 0 || CurrentNumber > NewCapacityValue || NewCapacityValue >= USHRT_MAX) return false;
        Capacity = NewCapacityValue;
        return true;
    }

    Airplane::Airplane() : UUID("{DEFAULT}"),Capacity(0) {}
    /**
     * 调用默认构造器需初始化
     * @param uuid
     * @param capacity
     * @return
     */
    bool Airplane::initUUIDAndCapacityOnce(const std::string& uuid, UShort capacity) {
        if(UUID != "{DEFAULT}" || uuid.empty() || tryModifyCapacity(capacity)) return false;
        UUID = uuid;
        return true;
    }

    Area::Area(std::string areaName): AreaName(std::move(areaName)) {}

    std::string Area::toString() {
        return AreaName;
    }

    bool Area::tryModifyName(const std::string& newName) {
        if(newName.empty() || std::equal(newName.begin(), newName.end(),AreaName.begin(),AreaName.end())) return false;
        AreaName = newName;
        return true;
    }

    Area::Area() {AreaName = "Default";}

    bool Area::initAreaNameOnce(const std::string &Name) {
        if(Name == "Default" ) return false;
        return tryModifyName(Name);
    }

    Flight::Flight(std::string uuid) :UUID(std::move(uuid)) {hadInit = false;}
    Flight::Flight() {UUID = "{Default}";hadInit = false;}

    std::string Flight::getUUID() {
        return UUID;
    }

    bool Flight::initValueOnce(class Airplane airplane, const Area& startingPoint, const Area& destination, const Date& departureTime, const Date::Time& takeTime) {
        if(hadInit) return false;
        Airplane = std::move(airplane);
        StartingPoint = startingPoint;
        Destination = destination;
        DepartureTime = departureTime;
        TakeTime = takeTime;
        hadInit = true;
        return true;
    }

    bool Flight::tryModifyAirplane(struct Airplane newAirplane) {
        if(newAirplane.getUUID() == "{DEFAULT}") return false;
        Airplane = std::move(newAirplane);
        return true;
    }

    bool Flight::tryChangeStartPointArea(Area area) {
        if(area.toString() == "Default") return false;
        StartingPoint = area;
        return true;
    }

    bool Flight::tryChangeDestinationArea(Area area) {
        if(area.toString() == "Default") return false;
        Destination = area;
        return true;
    }

    bool Flight::tryModifyDepartureDate(const COMPONENT::Date &date) {
        DepartureTime = date;
        return true;
    }

    bool Flight::tryModifyTakeTime(const Date::Time &time) {
        DepartureTime.getTime().setTime(time);
        return true;
    }

    class Airplane Flight::getAirplane() {
        return Airplane;
    }
    Area Flight::getStartingPointArea() {
        return StartingPoint;
    }
    Area Flight::getDestinationArea() {
        return Destination;
    }
    Date Flight::getDepartureTime() {
        return DepartureTime;
    }
    Date::Time Flight::getTakeTime() {
        return TakeTime;
    }

    bool Flight::initUUID(std::string uuid) {
        if(UUID != "{Default}") return false;
        UUID = std::move(uuid);
        return true;
    }


    User::User(std::string uuid) :UUID(std::move(uuid)) {}

    std::string User::getName() {
        return Name;
    }
    bool User::tryChangeName(const std::string& name) {
        if(name.empty()) return false;
        Name = name;
        return true;
    }

    std::string User::getUUID() {
        return UUID;
    }

    std::vector<Orders> User::getOrderList() {
        return OrderList;
    }
    std::vector<Chargebacks> User::getChargeBackList() {
        return ChargeBackList;
    }

    User::User() { this->UUID = "Default"; }

    bool User::initUUID(std::string uuid) {
        if(UUID != "Default") return false;
        UUID = std::move(uuid);
        return true;
    }


    Orders::Orders(User o, const Date& oD, const Flight& tF, const std::string& oU) {
        Owner = std::move(o);
        OrderCreatedDate = oD;
        TargetFlight = tF;
        OrderUUID = oU;
        Valid = false;
    }

    Orders *Orders::CreateOrder(User owner, const Date& orderCreateDate, const Flight& targetFlight, const std::string& orderUUID) {
        return new Orders(std::move(owner), orderCreateDate, targetFlight, orderUUID);
    }

    void Orders::enable(Orders od) {
        od.Valid = true;
    }
    void Orders::disable(Orders od) {
        od.Valid = false;
    }

    User Orders::getUser() {
        return Owner;
    }
    Date Orders::getOrderCreatedDate() {
        return OrderCreatedDate;
    }
    Flight Orders::getTargetFlight() {
        return TargetFlight;
    }
    std::string Orders::getOrderUUID() {
        return OrderUUID;
    }

    bool Orders::isValid() const {
        return Valid;
    }

    User Chargebacks::getUser() {
        return Owner;
    }

    Date Chargebacks::getChargebackCreatedDate() {
        return ChargebackCreateDate;
    }

    std::string Chargebacks::getChargebackUUID() {
        return ChargebackUUID;
    }

    Orders Chargebacks::getTargetOrder() {
        return TargetOrder;
    }

    bool Chargebacks::isSuccessful() {
        return Successful;
    }

    void Chargebacks::enable() {
        Successful = true;
    }

    Account::Account(airLifeHandler::AccountType accountType, std::string uuid) {
        switch (accountType) {
            case airLifeHandler::DEFAULT:
                _User = User(std::move(uuid));
                break;
            case airLifeHandler::ADMIN:
                AdministerUUID = uuid;
                break;
            case airLifeHandler::UNKNOWN:
                break;
        }
    }
} // COMPONENT