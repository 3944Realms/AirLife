//
// Created by f2561 on 24-5-9.
//

#include "component.h"

namespace COMPONENT {
    //Time Part method
    Time::Time(COMPONENT::UShort Hour, COMPONENT::UShort Minute){
            this->Hour = Hour;
            this->Minute = Minute;
    }
/**
 *
 * @param Hour
 * @param Minute
 * @return *Time
 */
    Time *Time::getTime(COMPONENT::UShort Hour, COMPONENT::UShort Minute) {
        try{
            if(Hour >= 24 || Minute >= 60) throw std::exception();

        }catch (std::exception& e){
            std::cerr<<"Worry Data"<<std::endl;
        }
        return new Time(Hour, Minute);
    }
    UShort Time::getHour() {
        return Hour;
    }
    UShort Time::getMinute() {
        return Minute;
    }
    std::string Time::toString(){
        using std::string,std::to_string;
        string hour,minute,toReturn;
        hour = to_string(Hour);
        minute = to_string(Minute);
        toReturn = hour + ":" + minute;
        return toReturn;
    }


    Time::~Time() {
        delete this;
    }
    //Date Part method
    Date::Date(COMPONENT::UShort Year, COMPONENT::UShort Month, COMPONENT::UShort Day, const COMPONENT::Time &time)  {
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
     *
     * @param Year
     * @param Month
     * @param Day
     * @param time
     * @return *Data
     */
     Date * Date::getDate(COMPONENT::UShort Year, COMPONENT::UShort Month, COMPONENT::UShort Day, const COMPONENT::Time& time) {
        try {
            if(Month > 12 || Day > getMonthDay(Year, Month)) throw std::exception();
        }catch(std::exception& e) {
            std::cerr<<"Worry Data"<<std::endl;
        }
        return new Date(Year, Month, Day, time);
    }
    std::string Date::toString() {
        using std::string,std::to_string;
        string year,month,day,Time,toReturn;
        year = to_string(Year);
        month = to_string(Month);
        day = to_string(Day);
        Time = time.toString();
        toReturn =  year + "/" + month + "/" + day + "-" + Time;
        return toReturn;
    }
    UShort Date::getYear() {
        return Year;
    }
    UShort Date::getMonth() {
        return Month;
    }
    UShort Date::getDay() {
        return Day;
    }
    Date::~Date() {
        delete this;
    }

} // COMPONENT