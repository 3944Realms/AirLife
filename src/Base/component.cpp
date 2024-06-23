#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by f2561 on 24-5-9.
//

#include "component.h"

#include <utility>

namespace COMPONENT {
class NaNException: public std::exception {
    const char * what() const noexcept override {
        return "NanOutput";
    }
};//继承is-a
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
            throw NaNException();
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

    std::vector<char> Date::Time::serialize() const {
        std::vector<char> data;

        data.insert(data.end(), reinterpret_cast<const char*>(&Hour), reinterpret_cast<const char*>(&Hour) + sizeof(Hour));
        data.insert(data.end(), reinterpret_cast<const char*>(&Minute), reinterpret_cast<const char*>(&Minute) + sizeof(Minute));

        return data;
    }

    Date::Time Date::Time::deserialize(const std::vector<char>& data) {
        Date::Time _time{};
        size_t offset = 0;

        UShort hour = 0;
        std::memcpy(&hour, data.data() + offset, sizeof(hour));
        offset += sizeof(hour);
        _time.Hour = hour;

        UShort minute = 0;
        std::memcpy(&minute, data.data() + offset, sizeof(minute));
        offset += sizeof(minute);
        _time.Minute = minute;
        return _time;

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
            std::cerr<<"Worry Data"<<std::endl;std::cerr<<"Worry Data"<<std::endl;
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

    std::vector<char> Date::serialize() const {

        std::vector<char> data;
        //序列化Year Month Day
        data.insert(data.end(), reinterpret_cast<const char*>(&Year), reinterpret_cast<const char*>(&Year) + sizeof(Year));
        data.insert(data.end(), reinterpret_cast<const char*>(&Month), reinterpret_cast<const char*>(&Month) + sizeof(Month));
        data.insert(data.end(), reinterpret_cast<const char*>(&Day), reinterpret_cast<const char*>(&Day) + sizeof(Day));
        //序列化timeData
        std::vector<char> timeData = time.serialize();
        size_t timeDataLen = timeData.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&timeDataLen), reinterpret_cast<const char*>(&timeDataLen) + sizeof(timeDataLen));
        data.insert(data.end(), timeData.begin(), timeData.end());
        return data;
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
    Date Date::deserialize(const std::vector<char>& data) {
        Date _date;
        size_t offset = 0;
        //反序列化年月日
        UShort Year,Month,Day;
        std::memcpy(&Year,data.data() + offset, UShortLen);
        offset += UShortLen;
        std::memcpy(&Month,data.data() + offset, UShortLen);
        offset += UShortLen;
        std::memcpy(&Day,data.data() + offset, UShortLen);
        offset += UShortLen;
        _date.Year = Year;
        _date.Month = Month;
        _date.Day = Day;
        //读取时间数据大小
        size_t timeDataSize;
        std::memcpy(&timeDataSize, data.data() + offset, sizeof (timeDataSize));
        offset += sizeof(timeDataSize);
        //读取时间数据序列化
        std::vector<char> timeData(data.begin() + offset, data.begin() + offset + timeDataSize);
        offset += timeDataSize;
        //将时间数据反序列化
        _date.time = Time::deserialize(timeData);

        return _date;
    }
#pragma clang diagnostic pop

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

    std::vector<char> Airplane::serialize() const {
       std::vector<char> data;

        size_t uuidLen = UUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&uuidLen), reinterpret_cast<const char*>(uuidLen) + sizeof(uuidLen));
        data.insert(data.end(), UUID.begin(), UUID.end());

        data.insert(data.end(), reinterpret_cast<const char*>(&Capacity), reinterpret_cast<const char*>(&Capacity) + UShortLen);
        data.insert(data.end(), reinterpret_cast<const char*>(&CurrentNumber), reinterpret_cast<const char*>(&CurrentNumber) + UShortLen);

        return data;
    }

    Airplane* Airplane::deserialize(const std::vector<char> &data) {
        size_t offset = 0;

        size_t uuidLen;
        std::memcpy(&uuidLen, data.data() + offset, sizeof(uuidLen));
        offset += sizeof(uuidLen);
        std::string uuid = std::string(data.data() + offset, uuidLen);
        auto it = airplaneRegistry.find(uuid);
        if(it != airplaneRegistry.end()) { return it->second; }
        auto* airplane = new Airplane();
        airplane->UUID = uuid;
        offset += uuidLen;

        UShort capacity;
        std::memcpy(&capacity, data.data() + offset, UShortLen);
        airplane->Capacity = capacity;
        offset += UShortLen;

        UShort currentNumber;
        std::memcpy(&currentNumber, data.data() + offset, UShortLen);
        offset += UShortLen;
        airplane->CurrentNumber = currentNumber;

        return airplane;
    }

    void Airplane::registerAirplane(Airplane *airplane) {
        airplaneRegistry[airplane->UUID] = airplane;
    }

    std::string Airplane::toString() {
        return   "{ AirplaneUUID:" + UUID + ", Capacity:" + std::to_string(Capacity) + " }";
    }


    Area::Area(std::string _uuid, std::string areaName) : UUID(std::move(_uuid)), AreaName(std::move(areaName)) {}
//  在改名前创建了一个类 改过名时 由类调用Sync()方法来同步成员类信息【检查 UUID 是否一致 -> 将引用指向Area】-> 之后如果有类创建时（谁用了它？ 怎么处理·1）
/*
 * 对于类成员对象属性需要引用，保存时序列化引用对象的内容，反序列化时
 */
    std::string Area::toString() {
        return "{ AreaUUID:" + UUID + ", AreaName:" + AreaName + " }";
    }

    bool Area::tryModifyName(const std::string& newName) {
        if(newName.empty() || std::equal(newName.begin(), newName.end(),AreaName.begin(),AreaName.end())) return false;
        AreaName = newName;
        return true;
    }

    Area::Area() {AreaName = "Default";}

    bool Area::initAreaNameAndUUIDOnce(const std::string &Name, std::string uuid) {
        if(Name == "Default" ) return false;
        else if(!Name.empty()) UUID = std::move(uuid);
        return tryModifyName(Name);
    }

    std::vector<char> Area::serialize() const {
        std::vector<char> data;
        size_t uuidLen = UUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&uuidLen), reinterpret_cast<const char*>(&uuidLen) + sizeof(uuidLen));
        data.insert(data.end(), UUID.begin(), UUID.end());
        size_t nameLen = AreaName.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&nameLen), reinterpret_cast<const char*>(&nameLen) + sizeof(nameLen));
        data.insert(data.end(), AreaName.begin(), AreaName.end());

        return data;
    }

    Area* Area::deserialize(const std::vector<char> &data) {
        size_t offset = 0;
        size_t uuidLen;
        std::memcpy(&uuidLen, data.data() + offset, sizeof(uuidLen));
        offset += sizeof(uuidLen);
        std::string uuid = std::string(data.data() + offset, uuidLen);
        auto it = areaRegistry.find(uuid);
        if(it != areaRegistry.end()) { return it->second; }
        Area *area = new Area();
        size_t nameLen;
        std::memcpy(&nameLen, data.data() + offset, sizeof(nameLen));
        offset += sizeof(nameLen);
        area->AreaName = std::string(data.data() + offset, nameLen);
        offset += nameLen;
        return area;
    }

    void Area::registerArea(Area *area) {
        areaRegistry[area->UUID] = area;
    }

    Flight::Flight(std::string uuid) :UUID(std::move(uuid)) {hadInit = false;}
    Flight::Flight() {UUID = "{Default}";hadInit = false;}

    std::string Flight::getUUID() {
        return UUID;
    }

    bool Flight::initValueOnce(class Airplane& airplane, Area& startingPoint, Area& destination, const Date& departureTime, const Date::Time& takeTime) {
        if(hadInit) return false;
        Airplane = &airplane;
        StartingPoint = &startingPoint;
        Destination = &destination;
        DepartureTime = departureTime;
        TakeTime = takeTime;
        hadInit = true;
        return true;
    }

    bool Flight::tryModifyAirplane(struct Airplane& newAirplane) {
        if(newAirplane.getUUID() == "{DEFAULT}") return false;
        Airplane = &newAirplane;
        return true;
    }

    bool Flight::tryChangeStartPointArea(Area& area) {
        if(area.getUUID() == "Default") return false;
        StartingPoint = &area;
        return true;
    }

    bool Flight::tryChangeDestinationArea(Area& area) {
        if(area.getUUID() == "Default") return false;
        Destination = &area;
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

    class Airplane* Flight::getAirplane() {
        return Airplane;
    }
    Area* Flight::getStartingPointArea() {
        return StartingPoint;
    }
    Area* Flight::getDestinationArea() {
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

    std::vector<char> Flight::serialize() const {
        std::vector<char> data;

        //序列化 UUID
        size_t uuidLen = UUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&uuidLen), reinterpret_cast<const char*>(&uuidLen) + sizeof(uuidLen));
        data.insert(data.end(), UUID.begin(), UUID.end());

        //序列化 Airplane;
        std::vector<char> airplaneData = Airplane->serialize();
        size_t airplaneDataSize = airplaneData.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&airplaneDataSize), reinterpret_cast<const char*>(&airplaneDataSize) + sizeof(airplaneDataSize));
        data.insert(data.end(), airplaneData.begin(), airplaneData.end());

        //序列化StartingPoint ,Destination
        std::vector<char> startingPointData = StartingPoint->serialize(), destinationData = Destination->serialize();
        size_t areaDataSize = sizeof(Area);
        data.insert(data.end(), reinterpret_cast<const char*>(&areaDataSize), reinterpret_cast<const char*>(&areaDataSize) + sizeof(areaDataSize));
        data.insert(data.end(), startingPointData.begin(), startingPointData.end());
        data.insert(data.end(), reinterpret_cast<const char*>(&areaDataSize), reinterpret_cast<const char*>(&areaDataSize) + sizeof(areaDataSize));
        data.insert(data.end(), destinationData.begin(), destinationData.end());

        //序列化DepartureTime
        std::vector<char> departureTimeData = DepartureTime.serialize();
        size_t departureTimeSize = departureTimeData.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&departureTimeSize), reinterpret_cast<const char*>(&departureTimeSize) + sizeof(departureTimeSize));
        data.insert(data.end(), departureTimeData.begin(), departureTimeData.end());

        //序列化TakeTime
        std::vector<char> takeTimeData = TakeTime.serialize();
        size_t takeTimeDataSize = takeTimeData.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&takeTimeDataSize), reinterpret_cast<const char*>(&takeTimeDataSize) + sizeof(takeTimeDataSize));
        data.insert(data.end(), takeTimeData.begin(), takeTimeData.end());

        //序列化hadInit
//        data.insert(data.end(), reinterpret_cast<const char*>(&hadInit), reinterpret_cast<const char*>(&hadInit) + sizeof(bool));
        data.push_back(hadInit? 1 : 0);
        return data;
    }

    Flight* Flight::deserialize(const std::vector<char> &data) {

        size_t offset = 0;

        //反序列化UUID
        size_t uuidLen;
        std::memcpy(&uuidLen, data.data() + offset, sizeof(uuidLen));
        offset += sizeof(uuidLen);
        std::string uuid(data.data() + offset, uuidLen);
        auto it = flightRegistry.find(uuid);
        if(it != flightRegistry.end()) { return it->second; }
        auto* flight = new Flight();
        flight->UUID = uuid;
        offset += uuidLen;


        //反序列化AirPlane
        size_t airplaneDataSize;
        std::memcpy(&airplaneDataSize, data.data() + offset, sizeof(airplaneDataSize));
        offset += sizeof(airplaneDataSize);
        std::vector<char> airplaneData(data.begin() + (int)offset, data.begin() + (int)offset + (int)airplaneDataSize);
        offset += airplaneDataSize;
        flight->Airplane = Airplane::deserialize(airplaneData);

        //反序列化StartingPoint ,Destination
        size_t areaDataSize;
        std::memcpy(&areaDataSize, data.data() + offset, sizeof(areaDataSize));
        offset += sizeof(areaDataSize);
        std::vector<char> startingPointData(data.begin() + (int)offset, data.begin() + (int)offset + (int)areaDataSize);
        offset += areaDataSize;
        std::memcpy(&areaDataSize, data.data() + offset, sizeof(areaDataSize));
        offset += sizeof(areaDataSize);
        std::vector<char> destinationData(data.begin() + (int)offset, data.begin() + (int)offset + (int)areaDataSize);
        offset += areaDataSize;
        flight->StartingPoint = Area::deserialize(startingPointData);
        flight->Destination = Area::deserialize(destinationData);

        //反序列化DepartureTime
        size_t departureTimeSize;
        std::memcpy(&departureTimeSize, data.data() + offset, sizeof(departureTimeSize));
        offset += sizeof(departureTimeSize);
        std::vector<char> departureTimeData(data.begin() + offset, data.begin() + offset + departureTimeSize);
        offset += departureTimeSize;
        flight->DepartureTime = Date::deserialize(departureTimeData);

        //反序列化TakeTime
        size_t takeTimeSize;
        std::memcpy(&takeTimeSize, data.data() + offset, sizeof(takeTimeSize));
        offset += sizeof(takeTimeSize);
        std::vector<char> takeTimeData(data.begin() + (int)offset, data.begin() + (int)offset + (int)takeTimeSize);
        offset += takeTimeSize;
        Date::Time takeTime = Date::Time::deserialize(takeTimeData);
        flight->TakeTime = takeTime;

        //反序列化hadInit
        bool _hadInit = (data[offset] == 1);
//        std::memcpy(&_hadInit, data.data() + offset, sizeof(_hadInit));
        flight->hadInit = _hadInit;
        offset += sizeof(bool);

        return flight;
    }

    void Flight::registerFlight(Flight *flight) {
        flightRegistry[flight->UUID] = flight;
    }

    std::string Flight::toString() {
        return "{ UUID:" + UUID +
                ", Airplane:{ UUID:" + Airplane->toString() +
                " }, StartingPoint:" + StartingPoint->toString() +
                ", Destination:" + Destination->toString() +
                ", DepartureTime:" + DepartureTime.toString() +
                " }";
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

    std::vector<Orders*> User::getOrderList() {
        return OrderList;
    }
    std::vector<Chargebacks*> User::getChargeBackList() {
        return ChargeBackList;
    }

    User::User() { this->UUID = "Default"; }

    bool User::initUUID(std::string uuid) {
        if(UUID != "Default") return false;
        UUID = std::move(uuid);
        return true;
    }
    std::vector<char> User::serialize() const {
        std::vector<char> data;
        //序列化UUID
        size_t uuidLen = UUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&uuidLen), reinterpret_cast<const char*>(&uuidLen) + sizeof(uuidLen));
        data.insert(data.end(), UUID.begin(), UUID.end());

        //序列化Name
        size_t nameLen = Name.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&nameLen), reinterpret_cast<const char*>(&nameLen) + sizeof(nameLen));
        data.insert(data.end(), Name.begin(), Name.end());

        //序列化OrderList
        size_t orderListSize = OrderList.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&orderListSize), reinterpret_cast<const char*>(&orderListSize) + sizeof(orderListSize));
        for (const auto& order : OrderList) {
            std::vector<char> orderData = order->serialize();
            data.insert(data.end(), orderData.begin(), orderData.end());
        }

        //序列化CheckBackList
        size_t chargeBackListSize = ChargeBackList.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&chargeBackListSize), reinterpret_cast<const char*>(&chargeBackListSize) + sizeof(chargeBackListSize));
        for (const auto& chargeback : ChargeBackList) {
            std::vector<char> chargebackData = chargeback->serialize();
            data.insert(data.end(), chargebackData.begin(), chargebackData.end());
        }

        return data;
    }

    User* User::deserialize(const std::vector<char>& data) {
        size_t offset = 0;

        //反序列化UUID
        size_t uuidLen;
        std::memcpy(&uuidLen, data.data() + offset, sizeof(uuidLen));
        offset += sizeof(uuidLen);
        std::string uuid = std::string(data.data() + offset, uuidLen);
        auto it = userRegistry.find(uuid);
        if(it != userRegistry.end()) { return it->second; } //如果存在
        User *user = new User();
        user->UUID = uuid;
        offset += uuidLen;

        //反序列化Name
        size_t nameLen;
        std::memcpy(&nameLen, data.data() + offset, sizeof(nameLen));
        offset += sizeof(nameLen);
        user->Name = std::string(data.data() + offset, nameLen);
        offset += nameLen;

        //反序列化OrderList list->order
        size_t orderListDataSize;
        std::memcpy(&orderListDataSize, data.data() + offset, sizeof(orderListDataSize));
        offset += sizeof(orderListDataSize);
        for (size_t i = 0; i < orderListDataSize; ++i) {
            Orders *order = Orders::deserialize(data, offset);
            user->OrderList.push_back(order);
        }

        //反序列化ChargeBackList
        size_t chargeBackListSize;
        std::memcpy(&chargeBackListSize, data.data() + offset, sizeof(chargeBackListSize));
        offset += sizeof(chargeBackListSize);
        for (size_t i = 0; i < chargeBackListSize; ++i) {
            Chargebacks *chargeback = Chargebacks::deserialize(data, offset);
            user->ChargeBackList.push_back(chargeback);
        }

        return user;
    }

    void User::registerUser(User *user) {
        userRegistry[user->UUID] = user;
    }

    User *User::getUserByUUID(const std::string& uuid) {
        auto it = userRegistry.find(uuid);
        if(it != userRegistry.end()) { return it->second; } //如果存在
        return nullptr;
    }


    Orders::Orders(User* o, const Date& oD, Flight* tF, const std::string& oU) : Owner(o) {
        OrderCreatedDate = oD;
        TargetFlight = tF;
        OrderUUID = oU;
        Valid = false;
    }

    Orders::Orders(std::string  ownerUUID, const Date &oD, Flight *tF, const std::string &oU)
        :OwnerUUID(std::move(ownerUUID)),
         OrderCreatedDate(oD),
         TargetFlight(tF),
         OrderUUID(ownerUUID),
         Valid(false) {}

    Orders::Orders() = default;

    Orders *Orders::CreateOrder(User& owner, const Date& orderCreateDate, Flight& targetFlight, const std::string& orderUUID) {
        return new Orders(&owner, orderCreateDate, &targetFlight, orderUUID);
    }

    void Orders::enable(Orders od) {
        od.Valid = true;
    }
    void Orders::disable(Orders od) {
        od.Valid = false;
    }

    User* Orders::getUser() {
        return User::getUserByUUID(OwnerUUID);
    }
    Date Orders::getOrderCreatedDate() {
        return OrderCreatedDate;
    }
    Flight* Orders::getTargetFlight() {
        return TargetFlight;
    }
    std::string Orders::getOrderUUID() {
        return OrderUUID;
    }

    bool Orders::isValid() const {
        return Valid;
    }
    std::vector<char> Orders::serialize() const {
        std::vector<char> data;
        //序列化OrderUUID
        size_t orderUUIDLen = OrderUUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&orderUUIDLen), reinterpret_cast<const char*>(&orderUUIDLen) + sizeof(orderUUIDLen));
        data.insert(data.end(), OrderUUID.begin(), OrderUUID.end());

        //序列化Owner[UUID]
        size_t ownerUUIDLen = OwnerUUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&ownerUUIDLen), reinterpret_cast<const char*>(&ownerUUIDLen) + sizeof(ownerUUIDLen));
        data.insert(data.end(), OwnerUUID.begin(), OwnerUUID.end());
        /* 已废弃直接写入USER（存在无限循环调用问题）*/
//        std::vector<char> ownerData = Owner->serialize();
//        data.insert(data.end(), ownerData.begin(), ownerData.end());

        //序列化OrderCreateDate
        std::vector<char> orderCreatedDateData = OrderCreatedDate.serialize();
        data.insert(data.end(), orderCreatedDateData.begin(), orderCreatedDateData.end());

        //序列化TargetFlightData
        std::vector<char> targetFlightData = TargetFlight->serialize();
        data.insert(data.end(), targetFlightData.begin(), targetFlightData.end());

        //序列化Valid
//        data.insert(data.end(), reinterpret_cast<const char*>(&Valid), reinterpret_cast<const char*>(&Valid) + sizeof(Valid));
        data.push_back(Valid ? 1 : 0);

        return data;
    }

    Orders* Orders::deserialize(const std::vector<char>& data, size_t& offset) {
        // 反序列化 OrderUUID
        size_t orderUUIDLen;
        std::memcpy(&orderUUIDLen, data.data() + offset, sizeof(orderUUIDLen));
        offset += sizeof(orderUUIDLen);
        std::string uuid = std::string(data.data() + offset, orderUUIDLen);
        auto it = orderRegistry.find(uuid);
        if(it != orderRegistry.end()) { return it->second; }
        auto* order = new Orders();
        order->OrderUUID = uuid;
        offset += orderUUIDLen;

        // 反序列化 Owner[UUID]
        size_t ownerUUIDLen;
        std::memcpy(&ownerUUIDLen, data.data() + offset , sizeof(ownerUUIDLen));
        offset += sizeof(ownerUUIDLen);
        std::string ownerData(data.begin() + (int)offset, data.begin() + (int)offset + (int)ownerUUIDLen);
        User* owner = User::getUserByUUID(ownerData);
        if(owner == nullptr) return nullptr;
        offset += ownerUUIDLen;
        /* 已废弃直接加载USER（存在无限循环调用问题）*/

        //反序列化 orderCreateDateSize
        size_t orderCreateDateSize;
        std::memcpy(&orderCreateDateSize, data.data() + offset, sizeof(orderCreateDateSize));
        offset += sizeof(orderCreateDateSize);
        std::vector<char> orderCreateDateData(data.begin() + (int)offset, data.begin() + (int)offset + (int)orderCreateDateSize);
        order->OrderCreatedDate = Date::deserialize(orderCreateDateData);
        offset += orderCreateDateSize;

        // 反序列化 OrderCreatedDate
        size_t orderCreatedDateDataSize;
        std::memcpy(&orderCreatedDateDataSize, data.data() + offset, sizeof(orderCreateDateSize));
        offset += sizeof(orderCreateDateSize);
        std::vector<char> orderCreatedDateData(data.begin() + (int)offset, data.begin() + (int)offset + (int)orderCreatedDateDataSize);
        order->OrderCreatedDate = Date::deserialize(orderCreatedDateData);
        offset += orderCreateDateSize;

        // 反序列化 TargetFlight
        size_t targetFlightDataSize;
        std::memcpy(&targetFlightDataSize, data.data() + offset, sizeof(targetFlightDataSize));
        offset += sizeof(targetFlightDataSize);
        std::vector<char> targetFlightData(data.begin() + (int)offset, data.begin() + (int)offset + (int)targetFlightDataSize);
        order->TargetFlight = Flight::deserialize(targetFlightData);
        offset += targetFlightDataSize;

        // 反序列化 Valid
//        std::memcpy(&order.Valid, data.data() + offset , sizeof(bool));
        order->Valid = (data[offset] == 1);
        offset += sizeof(bool);

        return order;
    }

    void Orders::registerOrder(Orders *order) {
        orderRegistry[order->OrderUUID] = order;
    }


    User* Chargebacks::getUser() {
        return User::getUserByUUID(OwnerUUID);
    }

    Date Chargebacks::getChargebackCreatedDate() {
        return ChargebackCreateDate;
    }

    std::string Chargebacks::getChargebackUUID() {
        return ChargebackUUID;
    }

    Orders* Chargebacks::getTargetOrder() {
        return TargetOrder;
    }

    bool Chargebacks::isSuccessful() const{
        return Successful;
    }

    void Chargebacks::enable() {
        Successful = true;
    }

    std::vector<char> Chargebacks::serialize() const {
        std::vector<char> data;
        // Serialize序列化 ChargebackUUID
        size_t uuidLength = ChargebackUUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&uuidLength), reinterpret_cast<const char*>(&uuidLength) + sizeof(uuidLength));
        data.insert(data.end(), ChargebackUUID.begin(), ChargebackUUID.end());

        // Serialize序列化 Owner(UUID)
        size_t ownerUUIDLen = OwnerUUID.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&ownerUUIDLen), reinterpret_cast<const char*>(&ownerUUIDLen) + sizeof(ownerUUIDLen));
        data.insert(data.end(), OwnerUUID.begin(), OwnerUUID.end());
        /* 已废弃直接写入USER（存在无限循环调用问题）*/
//        std::vector<char> ownerData = Owner->serialize();
//        data.insert(data.end(), ownerData.begin(), ownerData.end());

        // Serialize序列化 ChargebackCreateDate
        std::vector<char> dateData = ChargebackCreateDate.serialize();
        data.insert(data.end(), dateData.begin(), dateData.end());

        // Serialize序列化 TargetOrder
        std::vector<char> orderData = TargetOrder->serialize();
        data.insert(data.end(), orderData.begin(), orderData.end());

        // Serialize序列化 Successful flag
        data.push_back(Successful ? 1 : 0);

        return data;
    }

    Chargebacks* Chargebacks::deserialize(const std::vector<char> &data, size_t &offset)  {

        // Deserialize反序列化 ChargebackUUID
        size_t uuidLength;
        std::memcpy(&uuidLength, data.data() + offset, sizeof(uuidLength));
        offset += sizeof(uuidLength);
        std::string chargebackUUID(data.begin() + (int)offset, data.begin() + (int)offset + (int)uuidLength);
        offset += uuidLength;
        auto it = chargebacksRegistry.find(chargebackUUID);
        if(it != chargebacksRegistry.end()) { return it->second; }

        // Deserialize反序列化 Owner[UUID]
        size_t ownerUUIDLen;
        std::memcpy(&ownerUUIDLen, data.data() + offset , sizeof(ownerUUIDLen));
        offset += sizeof(ownerUUIDLen);
        std::string ownerData(data.begin() + (int)offset, data.begin() + (int)offset + (int)ownerUUIDLen);
        User* owner = User::getUserByUUID(ownerData);
        if(owner == nullptr) return nullptr;
        offset += ownerUUIDLen;
        /* 已废弃直接加载USER（存在无限循环调用问题）*/
//        size_t userDataSize;
//        std::memcpy(&userDataSize, data.data() + offset, sizeof(userDataSize));
//        offset += sizeof(userDataSize);
//        std::vector<char> userdata(data.begin() + (int)offset, data.begin() + (int)offset + (int)userDataSize);
//        User* owner = User::deserialize(userdata);
//        offset += userDataSize;

        // Deserialize反序列化 ChargebackCreateDate
        size_t chargebackCreateDataSize;
        std::memcpy(&chargebackCreateDataSize, data.data() + offset, sizeof(chargebackCreateDataSize));
        offset += sizeof(chargebackCreateDataSize);
        std::vector<char> chargebackCreateData(data.begin() + (int)offset, data.begin() + (int)offset + (int)chargebackCreateDataSize);
        Date chargebackCreateDate = Date::deserialize(chargebackCreateData);
        offset += chargebackCreateDataSize;

        // Deserialize反序列化 TargetOrder
        Orders* targetOrder = Orders::deserialize(data, offset);

        // Deserialize反序列化 Successful flag
        bool successful = (data[offset] == 1);
        offset += sizeof(bool);
        auto* chargeback = new Chargebacks(owner, chargebackCreateDate, targetOrder, chargebackUUID);
        chargeback->Successful = successful;

        return chargeback;
    }

    Chargebacks::Chargebacks() = default;

    Chargebacks::Chargebacks(User* o, const Date &oD, Orders* os, std::string oU) :Owner(o), ChargebackCreateDate(oD), TargetOrder(os), ChargebackUUID(std::move(oU)){ Successful = false;}

    void Chargebacks::registerChargeback(Chargebacks* chargebacks) {
        chargebacksRegistry[chargebacks->ChargebackUUID] = chargebacks;
    }

    Chargebacks::Chargebacks(std::string ownerUUID, const Date &oD, Orders *os, const std::string& cU)
            :OwnerUUID(std::move(ownerUUID)),
             ChargebackCreateDate(oD),
             TargetOrder(os),
             ChargebackUUID(cU),
             Successful(false) {}


    Account::Account(airLifeHandler::AccountType accountType, const std::string& uuid) {
        switch (accountType) {
            case airLifeHandler::DEFAULT:
                inf.AccountUser = new User(uuid);
                isValid = true;
                break;
            case airLifeHandler::ADMIN:
                inf.AdministerUUID = uuid;
                isValid = true;
                break;
            case airLifeHandler::UNKNOWN:
                isValid = false;
                break;
        }
        AccountType = accountType;
    }

    Account::Account(airLifeHandler::AccountType accountType, User& user) {
        switch (accountType) {
            case airLifeHandler::DEFAULT:
                inf.AccountUser = &user;
                isValid = true;
                break;
            case airLifeHandler::ADMIN:
                inf.AdministerUUID = user.getUUID();
                isValid = true;
                break;
            case airLifeHandler::UNKNOWN:
                isValid = false;
                break;
        }
        AccountType = accountType;
    }

    std::vector<char> Account::serialize() const {
        std::vector<char> data;

        // Serialize序列化 AccountType
        data.insert(data.end(), reinterpret_cast<const char*>(&AccountType), reinterpret_cast<const char*>(&AccountType) + sizeof(AccountType));

        // Serialize序列化 isValid
        data.push_back(isValid ? 1 : 0);

        //Serialize序列化 PasswordHash
        size_t pwHashDataLen = pwHash.size();
        data.insert(data.end(), reinterpret_cast<const char*>(&pwHashDataLen), reinterpret_cast<const char*>(&pwHashDataLen) + sizeof(pwHashDataLen));
        data.insert(data.end(), pwHash.begin(), pwHash.end());

        // Serialize序列化 union based on基于 AccountType
        if (AccountType == airLifeHandler::AccountType::DEFAULT) {
            std::vector<char> userData = inf.AccountUser->serialize();
            data.insert(data.end(), userData.begin(), userData.end());
        } else if (AccountType == airLifeHandler::AccountType::ADMIN) {
            size_t uuidLength = inf.AdministerUUID.size();
            data.insert(data.end(), reinterpret_cast<const char*>(&uuidLength), reinterpret_cast<const char*>(&uuidLength) + sizeof(uuidLength));
            data.insert(data.end(), inf.AdministerUUID.begin(), inf.AdministerUUID.end());
        }

        return data;
    }

    Account* Account::deserialize(const std::vector<char> &data) {
        size_t offset = 0;
        // Deserialize AccountType
        airLifeHandler::AccountType accountType;
        std::memcpy(&accountType, &data[offset], sizeof(accountType));
        offset += sizeof(accountType);

        // Deserialize isValid
        bool isValid = data[offset] == 1;
        offset += 1;

        // Create Account object
        auto *account = new Account(accountType, " ");

        // Set isValid field
        account->isValid = isValid;

        // Set Hash field
        size_t pwHashLength;
        std::memcpy(&pwHashLength, &data[offset], sizeof(pwHashLength));
        offset += sizeof(pwHashLength);
        std::string Hash(data.begin() + offset, data.begin() + offset + pwHashLength);
        account->pwHash = Hash;
        offset += pwHashLength;

        // Deserialize union based on AccountType
        if (accountType == airLifeHandler::AccountType::DEFAULT) {
            account->inf.AccountUser = User::deserialize(data);
        } else if (accountType == airLifeHandler::AccountType::ADMIN) {
            size_t uuidLength;
            std::memcpy(&uuidLength, &data[offset], sizeof(uuidLength));
            offset += sizeof(uuidLength);

            std::string uuid(data.begin() + offset, data.begin() + offset + uuidLength);
            offset += uuidLength;

            account->inf.AdministerUUID = uuid;
        }

        return account;
    }

    airLifeHandler::AccountType Account::getAccountType() {
        return AccountType;
    }

    User *Account::getAccountUser() const {
        return inf.returnAccUser();
    }

    std::string Account::getHash() const {
        return pwHash;
    }


} // COMPONENT
#pragma clang diagnostic pop