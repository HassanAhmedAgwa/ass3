#include"DayAppoinments.h"
DayAppoinments::DayAppoinments()
{

}

DayAppoinments::~DayAppoinments()
{

}
DayAppoinments::DayAppoinments(Appoinment *appoin,int numOfAppoin,string week_Day)
{
    appoinment=appoin;
    numOfAppoinments=numOfAppoin;
    weekDay=week_Day;
}
void DayAppoinments::SetAppoinmet(Appoinment *appoin)
{
    appoinment=appoin;
}
void DayAppoinments::SetNumOfAppoinments(int numOfAppoin)
{
    numOfAppoinments=numOfAppoin;
}
void DayAppoinments::SetWeekDay(string week_Day)
{
    weekDay=week_Day;
}
Appoinment* DayAppoinments::getAppoinmet()
{
    return appoinment;
}
int DayAppoinments::getNumOfAppoinments()
{
    return numOfAppoinments;
}
string DayAppoinments::getWeekDay()
{
    return weekDay;
}
DayAppoinments&DayAppoinments:: operator =(const DayAppoinments &DayAppoinments)
{
    this->appoinment=new Appoinment[DayAppoinments.numOfAppoinments];
    for(int i=0; i<DayAppoinments.numOfAppoinments; i++)
    {
        appoinment[i]=DayAppoinments.appoinment[i];
    }
    this->numOfAppoinments=DayAppoinments.numOfAppoinments;
    this->weekDay=DayAppoinments.weekDay;
}
DayAppoinments&DayAppoinments:: operator [](int i)
{
    int Size=sizeof(DayAppoinments)/sizeof(DayAppoinments[0]);
    if(i>Size){
        cout<<"Index out of bounds"<<endl;
        return this[0];
    }else{
        return this[i];
    }
}
bool DayAppoinments::operator ==( DayAppoinments DayAppoinments)
{
    if(this->appoinment==DayAppoinments.appoinment&&this->numOfAppoinments==DayAppoinments.numOfAppoinments&&this->weekDay==DayAppoinments.weekDay){
        return true;
    }else{
        return false;
    }
}
bool DayAppoinments::operator !=( DayAppoinments DayAppoinments)
{
    if(this->appoinment!=DayAppoinments.appoinment||this->numOfAppoinments!=DayAppoinments.numOfAppoinments||this->weekDay!=DayAppoinments.weekDay)
    {
        return true;
    }else{
        return false;
    }

}
std::ostream& operator<< (std::ostream& out, DayAppoinments &dayAppoinments)
{
    out<<"Week_Day of Appoinment/s is "<<dayAppoinments.weekDay<<endl;
    out<<"Number of Appoinment/s is "<<dayAppoinments.numOfAppoinments<<endl;
    for(int i=0;i<dayAppoinments.numOfAppoinments;i++){
        out<<i+1<<" Appoinment"<<endl;
        out<<"Start Time: ";
        Time s=dayAppoinments.getAppoinmet()[i].getStart();
        out<<s<<endl;
        out<<"End Time: ";
        Time e=dayAppoinments.getAppoinmet()[i].getEnd();
        out<<e<<endl;
    }
    return out;
}
std::istream& operator>> (std::istream& in, DayAppoinments &DayAppoinments)
{
    cout<<"Enter num of appoinment/s: ";
    int num;
    in>>num;
    DayAppoinments.SetNumOfAppoinments(num);
    Appoinment* appoin=new Appoinment[num];
    for(int i=0;i<num;i++){
        cout<<"Enter "<<i+1<<" appoinment"<<endl;
        Appoinment obj;
        in>>obj;
        bool check=false;
        for(int y=0;y<num;y++){
            if(appoin[y]==obj){
                check=true;
            }
        }
        if(check==false){
        appoin[i]=obj;
        }else{
            cout<<"This Time have appoinment,choose another time "<<endl;
            i--;
        }
    }
    DayAppoinments.SetAppoinmet(appoin);
    cout<<"Enter week_Day: ";
    string weekd;
    in>>weekd;
    DayAppoinments.SetWeekDay(weekd);
    return in;
}
