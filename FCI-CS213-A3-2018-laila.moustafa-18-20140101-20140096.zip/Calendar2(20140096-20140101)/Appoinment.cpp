#include"Appoinment.h"

Appoinment::Appoinment() {}
Appoinment::~Appoinment() {
    //delete;
}
Appoinment::Appoinment(Time s,Time e)
{
    if(s>e)
    {
        start=s;
        End=e;
    }
}
void Appoinment::SetStart(Time s)
{
    start=s;
}

void Appoinment::SetEnd(Time e)
{
    End=e;
}

Time Appoinment::getStart()
{
    return start;
}

Time Appoinment::getEnd()
{
    return End;
}

bool Appoinment::operator >( Appoinment appoinment)
{
    if(this->End>appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Appoinment::operator <( Appoinment appoinment)
{
    if(this->End<appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Appoinment::operator >=( Appoinment appoinment)
{
    if(this->End>appoinment.End || this->End==appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Appoinment::operator <=( Appoinment appoinment)
{
    if(this->End<appoinment.End || this->End==appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Appoinment::operator ==( Appoinment appoinment)
{
    if(this->start==appoinment.start && this->End==appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Appoinment::operator !=( Appoinment appoinment)
{
    if(this->start!=appoinment.start || this->End!=appoinment.End)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<< (std::ostream& out, Appoinment &appoinment)
{
    cout<<"Time Start: ";
    out<<appoinment.start<<endl;
    cout<<"Time End: ";
    out<<appoinment.End<<endl;
    return out;
}

std::istream& operator>> (std::istream& in, Appoinment &appoinment)
{
    Time s;
    Time e;
    cout<<"Enter the start time for appoinment: "<<endl;
    in>>s;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Enter the End time for appoinment: "<<endl;
    in>>e;

    while(e<s || e==s)
    {
        cout<<"Appoinment is not valid !"<<endl;
        cout<<"Enter the End time for appoinment: "<<endl;
        in>>e;

    }
    appoinment.SetStart(s);
    appoinment.SetEnd(e);
    return in;
}

