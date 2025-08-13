#include "leapyear.h"
int isLeapYear(int yy)
{
    if (yy < 0)
    {
        return -1;
    }
    if (yy % 4 == 0)
    {
        if (yy % 100 == 0)
        {
            if (yy % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}