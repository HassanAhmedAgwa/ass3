#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include<sstream>

using namespace std;

vector<string> collection;
/******************************************************************/
void get( string str, string res )
{
    collection.push_back(res);
    for( int i = 0; i < str.length(); i++ )
        get( string(str).erase(i,1), res + str[i] );
}
/******************************************************************/
string convertToString(int x)
{
    string s;
    ostringstream temp;
    temp<<x;
    s=temp.str();
    return s;
}
/******************************************************************/
int convertToInt(char c)
{
    int x=(int)c-48;
    return x;
}
/******************************************************************/
string ConvertVecToString(vector<int> vec)
{
    string TheReturn="";
    for(int i=0; i<vec.size(); i++)
    {
        TheReturn+=convertToString(vec.at(i));
    }
    return TheReturn;
}
/******************************************************************/
vector<int>ConvertStrToVec(string str)
{
    vector<int> vect;
    for(int i=0; i<str.length(); i++)
    {
        vect.push_back(convertToInt(str.at(i)));
    }
    return vect;
}
/******************************************************************/
vector<int>difference(vector<int>vec1,vector<int>vec2 /*elkaml*/)
{
    vector <int>diff;
    int found;
    for(int i=0; i<vec1.size(); i++)
    {
        for(int j=0; j<vec2.size(); j++)
        {
            if(vec1.at(i)==vec2.at(j))
            {
                found=0;
            }
            else
            {
                found=vec2.at(j);
            }
            if(found!=0)
            {
                diff.push_back(found);
            }
        }
    }
    return diff;
}
/******************************************************************/

bool isMeasurable(int target, vector<int> & weights)
{
    bool boolean=false;
    string weightStr=ConvertVecToString(weights);
    //make Combination
    get(weightStr,"");
    //+//
    for(int i=0; i<collection.size(); i++)
    {
        string index=collection.at(i);
        int result=0;
        for(int j=0; j<index.length(); j++)
        {
            result+=convertToInt(index.at(j));
        }
        if(result==target)
        {
            boolean=true;
            return boolean;
        }
    }
    //+//-//
    for(int i=0; i<collection.size(); i++)
    {
        string index=collection.at(i);
        vector<int>indexVec=ConvertStrToVec(index);
        vector<int>diff=difference(indexVec,weights);
        int result=0;
        for(int j=0; j<index.length(); j++)
        {
            result+=convertToInt(index.at(j));
        }
        for(int j=0; j<diff.size(); j++)
        {
            result-=diff.at(j);
        }
        if(result==target)
        {
            boolean=true;
            return boolean;
        }
    }
    //-//+//
    for(int i=0; i<collection.size(); i++)
    {
        string index=collection.at(i);
        vector<int>indexVec=ConvertStrToVec(index);
        vector<int>diff=difference(indexVec,weights);
        int result=0;
        for(int j=0; j<diff.size(); j++)
        {
            result+=diff.at(j);
        }
        for(int j=0; j<index.length(); j++)
        {
            result-=convertToInt(index.at(j));
        }
        if(result==target)
        {
            boolean=true;
            return boolean;
        }
    }
    return boolean;
}
/******************************************************************/
int main( int argc, char **argv)
{
    vector<int> sampleWeights;
    sampleWeights.push_back(2);
    sampleWeights.push_back(5);
    if(isMeasurable(4,sampleWeights)==true)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
