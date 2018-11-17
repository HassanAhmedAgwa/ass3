#include <iostream>
#include"Time.h"
#include"Appoinment.h"
#include"DayAppoinments.h"
#include"Calendar.h"
using namespace std;

int main()
{
    bool online=true;
    while(online==true)
    {
        Calendar c;
        int choose;
        cout<<"1- Insert appoinment for specific day or multiple day"<<endl;
        cout<<"2- Display appoinment for a day or the week"<<endl;
        cout<<"3- Delete appoinment"<<endl;
        cout<<"4- Make all appoinments for a day equal another day"<<endl;
        cout<<"5- Check if two day have equal appoinments"<<endl;
        cout<<"***Choose what you are want: ";
        cin>>choose;
        while(choose>5 || choose<1)
        {
            cout<<"Enter validate choice"<<endl;
            cin>>choose;
        }
        if(choose==1)
        {
            DayAppoinments * dayS;
            DayAppoinments day;
            cin>>day;
            dayS[0]=day;
            cout<<"if you want to add another appoinment ,click (1) ,else click (0): ";
            int ch;
            cin>>ch;
            int counter=1;
            if(ch==1)
            {
                cin>>day;
                dayS[counter]=day;
                counter++;
                cout<<"if you want to add another appoinment ,click (1) ,else click (0): ";
                cin>>ch;
            }
            c.SetDayAppoinments(dayS);
            c.SetNumOfAppoinments(counter-1);
        }
        else if(choose==2)
        {
            cout<<"Display for day or week, Enter (0) for day, Or Enter (1) for week:";
            int ch;
            cin>>ch;
            if(ch==1)
            {
                for(int i=0; i<c.getNumOfDays(); i++)
                {
                    DayAppoinments d=c.getDayAppoinments()[i];
                    cout<<d<<endl;
                }
            }
            else if(ch==0)
            {
                cout<<"Enter a day that want to display: ";
                string day;
                cin>>day;
                for(int i=0; i<c.getNumOfDays(); i++)
                {
                    string day2=c.getDayAppoinments()[i].getWeekDay();
                    if(day==day2)
                    {
                        DayAppoinments d=c.getDayAppoinments()[i];
                        cout<<d<<endl;
                        break;
                    }
                }
            }
        }
        else if(choose==3)
        {
            cout<<"Insert appoinment u want to delete"<<endl;
            Appoinment appoin;
            cin>>appoin;
            for(int i=0; i<c.getNumOfDays(); i++)
            {
                Appoinment appoin2;
                for(int y=0; y<c.getNumOfAppoinments(); y++)
                {
                    appoin2=c.getDayAppoinments()[i].getAppoinmet()[y];
                    if(appoin2==appoin)
                    {
                        c.getDayAppoinments()[i].getAppoinmet()[y].~Appoinment();
                    }
                }
            }
        }
        else if(choose==4)
        {
            string day1;
            string day2;
            cout<<"Enter a day that you want to add in: ";
            cin>>day1;
            cout<<"Enter a day that you want to add from: ";
            cin>>day2;
            for(int i=0;i<c.getNumOfDays();i++){
                string comp=c.getDayAppoinments()[i].getWeekDay();
                if(comp==day2){

                    break;
                }
            }
        }
        else if(choose==5)
        {
            string day1;
            string day2;
            cout<<"Enter day-1 and day-2 "<<endl;
            cin>>day1>>day2;
            DayAppoinments obj1;
            DayAppoinments obj2;
            for(int i=0; i<c.getNumOfDays(); i++)
            {
                string comp=c.getDayAppoinments()[i].getWeekDay();
                if(day1==comp)
                {
                    obj1=c.getDayAppoinments()[i];
                }
                if(day2==comp)
                {
                    obj2=c.getDayAppoinments()[i];
                }
                if(obj1==obj2)
                {
                    cout<<"Two days have same appoinments "<<endl;
                }
            }
        }
        cout<<"**Want to finish ,if you want click (1)"<<endl;
        int exit;
        cin>>exit;
        if(exit==1)
        {
            online==false;
        }

    }
    return 0;
}
