#include"Calendar.h"
Calendar::Calendar()
{

}
Calendar::~Calendar()
{

}
Calendar::Calendar(DayAppoinments *dayS,int NumOfDays)
{
    days=dayS;
    numOfDays=NumOfDays;
}
void Calendar::SetDayAppoinments(DayAppoinments *dayS)
{
    days=dayS;
}
void Calendar::SetNumOfDays(int NumOfDays)
{
    numOfDays=NumOfDays;
}
DayAppoinments* Calendar::getDayAppoinments()
{
    return days;
}
int Calendar::getNumOfDays()
{
    return numOfDays;
}
