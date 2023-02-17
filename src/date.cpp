/**
 * @file date.cpp
 * @author Kilian Soucy-Dufour (cs.kilian@proton.me)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "date.h"

/**
 * @brief get DateTime structure as a string that represent the current date.
 * 
 * @return returns a std::string containing the current date in a human-friendly readable format.
 */
std::string DateTime::get_string() {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << '-'
       << std::setw(2) << month << '-'
       << std::setw(2) << day << ' '
       << std::setw(2) << hour << ':'
       << std::setw(2) << minute << ':'
       << std::setw(2) << second;
    return ss.str();
}

/**
 * @brief print the date as a human-friendly readable string.
 * 
 */
void DateTime::printDate() {
    std::cout << get_string() << std::endl;
}

/**
 * @brief verify if a year is leap or not.
 * 
 * @return returns true if the year is leap
 * @return returns false if the year is not leap. 
 */
bool DateTime::is_leap(){
    if (year % 4 != 0){
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

/**
 * @brief Get the current date object
 * 
 * @return DateTime filled with the current date data.
 */
DateTime get_current_date(){
    DateTime d;
    time_t t = time(0);
    tm *now = localtime(&t);

    d.setYear(now->tm_year + 1900);
    d.setMonth(now->tm_mon + 1);
    d.setDay(now->tm_mday);
    d.setHour(now->tm_hour);
    d.setMinute(now->tm_min);
    d.setSecond(now->tm_sec);
    d.setDayOfWeek((Weekday)now->tm_mday);
    return d; 
}

/**
 * @brief calculate the difference in days between two dates.
 * 
 * @param d1 date one.
 * @param d2  date two.
 * @return int representing the difference in days.
 */
int get_day_difference(const DateTime& d1, const DateTime& d2){
    struct tm tm1, tm2;
    std::time_t t1, t2;
    
    // set tm1 from d1
    
    tm1.tm_year = d1.getYear() - 1900;
    tm1.tm_mon = d1.getMonth() - 1;
    tm1.tm_mday = d1.getDay();
    tm1.tm_hour = d1.getHour();
    tm1.tm_min = d1.getMinute();
    tm1.tm_sec = d1.getSecond();
    tm1.tm_isdst = -1;

    // set tm2 from d2
    tm2.tm_year = d2.getYear() - 1900;
    tm2.tm_mon = d2.getMonth() - 1;
    tm2.tm_mday = d2.getDay();
    tm2.tm_hour = d2.getHour();
    tm2.tm_min = d2.getMinute();
    tm2.tm_sec = d2.getSecond();
    tm2.tm_isdst = -1;

    t1 = std::mktime(&tm1);
    t2 = std::mktime(&tm2);
    if(t1 == -1 || t2 == -1){
        return -1;
    }

    return (t1 - t2) / 86400;
}

/**
 * @brief calculate the difference in seconds between two dates.
 * 
 * @param d1 date one.
 * @param d2  date two.
 * @return int representing the difference in seconds.
 */
int get_second_difference(const DateTime& d1, const DateTime& d2){
    struct tm tm1, tm2;
    std::time_t t1, t2;
    
    // set tm1 from d1
    
    tm1.tm_year = d1.getYear() - 1900;
    tm1.tm_mon = d1.getMonth() - 1;
    tm1.tm_mday = d1.getDay();
    tm1.tm_hour = d1.getHour();
    tm1.tm_min = d1.getMinute();
    tm1.tm_sec = d1.getSecond();
    tm1.tm_isdst = -1;

    // set tm2 from d2
    tm2.tm_year = d2.getYear() - 1900;
    tm2.tm_mon = d2.getMonth() - 1;
    tm2.tm_mday = d2.getDay();
    tm2.tm_hour = d2.getHour();
    tm2.tm_min = d2.getMinute();
    tm2.tm_sec = d2.getSecond();
    tm2.tm_isdst = -1;

    t1 = std::mktime(&tm1);
    t2 = std::mktime(&tm2);
    if(t1 == -1 || t2 == -1){
        return -1;
    }

    std::cout << static_cast<int>(std::difftime(t1, t2)) << std::endl;
    return static_cast<int>(std::difftime(t1, t2));
}