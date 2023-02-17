/**
 * @file date.h
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iomanip> 
#include <iostream>
#include <ctime>

/* 
Depending on the timezone we wants to support, if we want to support only a few timezones we can use an enum as follows,
but if you want to support all the timezones you're better to go directly with a library, for now we'll keep it like this,
until feeling like changing it.
*/

/**
 * @brief this enum represent a few of the timezones available.
 * 
 */
enum class Timezone {
    UTC, EST, CST, MST, PST
};

/**
 * @brief this enum represents all the day of the week.
 * 
 */
enum Weekday {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};


/**
 * @brief the DateTime structure is a date object.
 * 
 */
struct DateTime {
    DateTime(){}

    DateTime(int y, int m, int d)
            : year(y), month(m), day(d), 
              hour(0), minute(0), second(0) {}

    DateTime(int y, int m, int d, int h, int min, int s) 
            : year(y), month(m), day(d), 
              hour(h), minute(min), second(s) {}

    ~DateTime(){}

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    Weekday getDayOfWeek() const { return day_of_week; }

    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }
    void setDayOfWeek(Weekday d) { day_of_week = d; }

    void printDate();
    std::string get_string();
    bool is_leap();
private:
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    Weekday day_of_week;
};

DateTime get_current_date();
int get_day_difference(const DateTime& d1, const DateTime& d2);
int get_second_difference(const DateTime& d1, const DateTime& d2);

#endif