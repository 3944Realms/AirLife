//
// Created by f2561 on 24-5-9.
//

#ifndef AIRLIFE_COMPONENT_H
#define AIRLIFE_COMPONENT_H

#include <cstddef>
#include <exception>
#include <iostream>

namespace COMPONENT {

    typedef unsigned short UShort;
    class Time {
    private:
        UShort Hour;
        UShort Minute;
        Time(UShort Hour, UShort Minute);

    public:
        Time() = default;
        static Time *getTime(UShort Hour, UShort Minute);
        std::string toString();
        UShort getHour();
        UShort getMinute();
        ~Time();
    };
    class Date {
    private:
        UShort Year;
        UShort Month;
        UShort Day;
        Time time{};
        static UShort getMonthDay(UShort Year, UShort Month);
        Date(UShort Year, UShort Month, UShort Day, const Time& time);
        ~Date();
    public:
        static Date *getDate(UShort Year, UShort Month, UShort Day, const Time& time);
        UShort getYear();
        UShort getMonth();
        UShort getDay();
        std::string toString();
    };


} // COMPONENT

#endif //AIRLIFE_COMPONENT_H
