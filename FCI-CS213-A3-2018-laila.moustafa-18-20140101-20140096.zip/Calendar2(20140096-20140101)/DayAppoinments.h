#ifndef DAYAPPOINMENTS_H_INCLUDED
#define DAYAPPOINMENTS_H_INCLUDED

#include"Appoinment.h"

class DayAppoinments: public Appoinment{
    private:
        Appoinment * appoinment;
        int numOfAppoinments;
        string weekDay;
    public:
        DayAppoinments();
        ~DayAppoinments();
        DayAppoinments(Appoinment *appoinment,int numOfAppoinments,string weekDay);
        void SetAppoinmet(Appoinment *appoinment);
        void SetNumOfAppoinments(int numOfAppoinments);
        void SetWeekDay(string weekDay);
        Appoinment* getAppoinmet();
        int getNumOfAppoinments();
        string getWeekDay();
        virtual DayAppoinments& operator =(const DayAppoinments &DayAppoinments);
        virtual DayAppoinments& operator [](int i);
        virtual bool operator ==( DayAppoinments DayAppoinments);
        virtual bool operator !=( DayAppoinments DayAppoinments);
        friend std::ostream& operator<< (std::ostream& out, DayAppoinments &DayAppoinments);
        friend std::istream& operator>> (std::istream& in, DayAppoinments &DayAppoinments);

};


#endif // DAYAPPOINMENTS_H_INCLUDED
