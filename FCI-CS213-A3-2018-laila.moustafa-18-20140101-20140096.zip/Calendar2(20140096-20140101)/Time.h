#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include<iostream>
using namespace std;

class Time{
    private:
        int hour;
        int minute;
        string daynight;
    public:
        Time();
        virtual ~Time();
        Time(int hr,int min,string day);
        void SetHour(int hr);
        void SetMin(int min);
        void SetDay(string day);
        int getHour();
        int getMin();
        string getDay();
        virtual bool operator >( Time time);
        virtual bool operator <( Time time);
        virtual bool operator ==( Time time);
        virtual bool operator !=( Time time);
        friend ostream& operator<< (ostream& out, Time &time);
        friend istream& operator>> (istream& in, Time &time);
};


#endif // TIME_H_INCLUDED
