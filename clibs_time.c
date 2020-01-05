#include <time.h>
#include "clibs_time.h"

struct tm date_create(
    int year,
    int month,
    int day)
{
    return time_create(year, month, day, 9, 0, 0);
}

struct tm time_create(
    int year,
    int month,
    int day,
    int hour,
    int min,
    int sec)
{
    int _y = year - 1900;
    int _m = month - 1;

    struct tm t = {0};

    t.tm_year = _y;
    t.tm_mon = _m;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = min;
    t.tm_sec = sec;

    return t;
}
