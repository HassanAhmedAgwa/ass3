#ifndef APPOINMENT_H_INCLUDED
#define APPOINMENT_H_INCLUDED

#include"Time.h"

class Appoinment :public Time{
    private:
        Time start;
        Time End;
    public:
        Appoinment();
        ~Appoinment();
        Appoinment(Time s,Time e);
        void SetStart(Time s);
        void SetEnd(Time e);
        Time getStart();
        Time getEnd();
        virtual bool operator >( Appoinment appoinment);
        virtual bool operator <( Appoinment appoinment);
        virtual bool operator >=( Appoinment appoinment);
        virtual bool operator <=( Appoinment appoinment);
        virtual bool operator ==( Appoinment appoinment);
        virtual bool operator !=( Appoinment appoinment);
        friend std::ostream& operator<< (std::ostream& out, Appoinment &appoinment);
        friend std::istream& operator>> (std::istream& in, Appoinment &appoinment);

};


#endif // APPOINMENT_H_INCLUDED
