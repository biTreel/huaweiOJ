/*
 * Author: biTree
 * Date: June,12,2016
 */

#include <iostream>
#include <cmath>
#define uint unsigned int
using namespace std;

uint CalcAutomorphicNumbers(uint n);
int main(){
    uint n,count=0;
    cin>>n;
    count=CalcAutomorphicNumbers(n);
    cout<<count<<endl;
    return 0;
}

uint CalcAutomorphicNumbers(uint n){
    long n2;
    uint cnt=0;
    for(uint i=0;i<=n;++i){
        n2=i*i;
        if(i<10){
            if(n2%10==i)
                cnt++;
                //cout<<i<<endl;
        }
        else if(10<=i && i<100){
            if(n2%100==i)
                cnt++;
                //cout<<i<<endl;
        }
        else if(100<=i && i<1000){
            if(n2%1000==i)
                cnt++;
                //cout<<i<<endl;
        }
        else
            continue;
    }
    return cnt;
}

