/*
 * Author: biTree
 * Date: June,16,2016
 */

#include <iostream>
using namespace std;
static int i=5;
static double getJourney(double high);
static double getFifthHigh(double high);
int main(){
    double high;
    double journey,fifthHigh;
    cin>>high;
    journey=getJourney(high);
    fifthHigh=getFifthHigh(high);
    cout.unsetf(ios::showpoint);   
    cout<<journey<<endl;
    cout<<fifthHigh<<endl;
    return 0;
}

static double getJourney(double high){
    //four times
    if(--i)
        return high*3/2+getJourney(high/2);
    //last time
    return high;
}
static double getFifthHigh(double high){
    while(i++!=5)
        high/=2;
    return high;
}
