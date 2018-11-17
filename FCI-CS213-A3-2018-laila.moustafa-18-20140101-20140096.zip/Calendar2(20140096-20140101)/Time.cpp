#include"Time.h"
#include<iostream>
#include<iomanip>
using namespace std;

Time::Time()
{
    hour=01;
    minute=00;
    daynight="AM";
}
Time:: ~Time() {}

Time::Time(int hr,int min,string day)
{
    hour=01;
    minute=00;
    daynight="AM";

    if(hr>0 && hr<=12)
    {
        hour=hr;
    }
    if(min>0 && min<=60)
    {
        minute=min;
    }
    if(day=="AM" || day=="PM")
    {
        daynight=day;
    }
}
void Time:: SetHour(int hr)
{
    if(hr>0 && hr<=12)
    {
        hour=hr;
    }
}
void Time:: SetMin(int min)
{
    if(min>=0 && min<=60)
    {
        minute=min;
    }
}
void Time::SetDay(string day)
{
    if(day=="AM" || day=="PM")
    {
        daynight=day;
    }
}
int Time::getHour()
{
    return hour;
}
int Time::getMin()
{
    return minute;
}
string Time::getDay()
{
    return daynight;
}
bool Time::operator <( Time time)
{
    if(this->hour<time.hour)
    {
        if(this->daynight==time.daynight)
        {
            return true;
        }
        else
        {
            if(this->daynight=="AM" && time.daynight=="PM")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(this->hour==time.hour)
    {
        if(this->minute<time.minute)
        {
             if(this->daynight==time.daynight)
            {
                return true;
            }
        }
        else if(this->minute==time.minute)
        {
            if(this->daynight==time.daynight)
            {
                return true;
            }
            else if(this->daynight=="AM" && time.daynight=="PM")
            {
                return true;
            }
            else
            {
                return false;
            }
        }else{
            return false;
        }
    }
    else
    {
        return false;
    }

}
bool Time::operator >( Time time)
{
    if(this->hour>time.hour)
    {
        if(this->daynight==time.daynight)
        {
            return true;
        }
        else
        {
            if(this->daynight=="PM" && time.daynight=="AM")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(this->hour==time.hour)
    {
        if(this->getMin()>time.getMin())
        {

            if(this->daynight==time.daynight)
            {
                return true;
            }
        }
        else if(this->minute==time.minute)
        {
             if(this->daynight==time.daynight)
            {
                return true;
            }
            else if(this->daynight=="PM" && time.daynight=="AM")
            {
                return true;
            }
            else
            {
                return false;
            }
        }else{
            return false;
        }
    }
    else
    {
        return false;
    }


}
bool Time::operator ==( Time time)
{
    if(this->daynight==time.daynight)
    {
        if(this->hour==time.hour)
        {
            if(this->minute==time.minute)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
bool Time::operator !=( Time time)
{
    if(this->daynight!=time.daynight)
    {
        if(this->hour!=time.hour)
        {
            if(this->minute!=time.minute)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
ostream& operator<< (std::ostream& out, Time &time)
{
    out<<endl<<time.hour<<":"<<time.minute<<" "<<time.daynight;
    return out;
}
istream& operator>> (istream& in, Time &time)
{
    int hr;
    int miN;
    string dayNight;
    cout<<endl<<"Enter day-night[between AM or PM]:";
    in>>dayNight;
    time.SetDay(dayNight);
    cout<<endl<<"Enter hour[between 01 : 12]:";
    in>>hr;
    time.SetHour(hr);
    cout<<endl<<"Enter minute[between 00 : 60]:";
    in>>miN;
    cout<<endl;
    time.SetMin(miN);
    return in;
}
