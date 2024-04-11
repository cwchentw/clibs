/** @file       clibs_time.h
 *  @brief      Common time operations.
 *  @author     OpenTechCoder
 *  @copyright  MIT
 */
#ifndef CLIBS_TIME_H
#define CLIBS_TIME_H

#include <time.h>

/** @fn      struct tm date_create(int year, int month, int day)
 *  @brief   Create a date object.
 *  @param   year  year in Gregorian calendar
 *  @param   month from 1 to 12
 *  @param   day   from 1 to 31
 *  @return  struct tm
 * 
 *  Time is kept at 9:00 AM.
 */
struct tm date_create(
    int year, int month, int day);

/** @fn      struct tm time_create(int year, int month, int day, int hour, int min, int sec)
 *  @brief   Create a time object.
 *  @param   year  year in Gregorian calendar
 *  @param   month from 1 to 12
 *  @param   day   from 1 to 31
 *  @param   hour  from 0 to 23
 *  @param   min   from 0 to 59
 *  @param   sec   from 0 to 59
 *  @return  struct tm
 */
struct tm time_create(
    int year, int month, int day, int hour, int min, int sec);

#endif  /* CTIME_UTILS_H */