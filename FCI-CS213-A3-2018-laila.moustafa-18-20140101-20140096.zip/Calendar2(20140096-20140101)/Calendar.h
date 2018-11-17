#ifndef CALENDAR_H_INCLUDED
#define CALENDAR_H_INCLUDED

#include"DayAppoinments.h"

class Calendar:public DayAppoinments{
    private:
        DayAppoinments  *days;
        int numOfDays;
    public:
        Calendar();
        ~Calendar();
        Calendar(DayAppoinments *days,int numOfDays);
        void SetDayAppoinments(DayAppoinments *days);
        void SetNumOfDays(int numOfDays);
        DayAppoinments* getDayAppoinments();
        int getNumOfDays();

};



#endif // CALENDAR_H_INCLUDED
