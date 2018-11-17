#include <iostream>
using namespace std;

void numOfBars(int& res, int& cop){

    if (cop < 7){
        return;
    }
    else if (cop == 7){
        res += 1;
        cop -=  7;
        return;
    }
    int temp = cop/7;
    cop += temp;
    res += temp;
    cop -= temp * 7;

    return numOfBars(res, cop);

}
int main()
{
    int money = 25;

    int chocolateBars = money;
    int coupons = money;

    numOfBars(chocolateBars, coupons);
    cout << chocolateBars << " chocolate bars.\n" << coupons << " coupons leftover."<< endl;
    return 0;
}
