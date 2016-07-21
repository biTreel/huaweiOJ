/*
 * Author:biTree
 * Date: June,11,2016
 */

#include <iostream>
#include <string>
using namespace std;
#define uint unsigned int
bool isMin(uint,uint*,string );
string delChar(string);
int main(){
    string str;
    cin>>str;
    str=delChar(str);
    cout<<str;
    return 0;
}

bool isMin(uint cnt,uint* arr,string s){
    //uint i=0;
    for(uint i=0;i!=s.size();++i){
        if(cnt>arr[s.at(i)])
            return false;
    }
    return true;
}
string delChar(string str){
    const int MAX=256;
    uint count[MAX]={0};
    for(uint i=0;i!=str.size();++i)
        count[str.at(i)]++;
    string str2=str;
    for(uint i=0;i!=str.size();++i){
        if(isMin(count[str.at(i)],count,str2)){
            str.erase(i,1);
            --i;
        }
    }
    return str;
}
