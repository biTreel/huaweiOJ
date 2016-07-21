/* * Author: biTree * Date: June,17,2016 */#include <iostream>#include <string>#include <cctype>using namespace std;bool isDigit(string str);bool isLegalIP(string strIP);int strtoI(string str);int main(){    string IP;    getline(cin,IP);    if(isLegalIP(IP))        cout<<"YES"<<endl;    else        cout<<"NO"<<endl;    return 0;}bool isLegalIP(string strIP){    bool flag=true;    string::iterator it1=strIP.begin();    string::iterator it2;    it2=it1;    int num;    while(1){        while(*it2 != '.'){            if(it2==strIP.end())                break;            ++it2;        }        string tmp(it1,it2);        //cout<<*it2<<endl;        //cout<<tmp<<endl;        if(!isDigit(tmp)){            flag=false;            break;        }        num=strtoI(tmp);        //cout<<num<<endl;        if(num<0 || 255<num){            flag=false;            break;        }        if(it2==strIP.end())            break;        ++it2;        it1=it2;    }    return flag;}bool isDigit(string str){    bool flag=true;    for(size_t i=0;i!=str.size();++i)        if(!isdigit(str[i]))            flag=false;    return flag;}int strtoI(string str){    int res=0;    for(size_t i=0;i!=str.size();++i)        res=res*10+str[i]-'0';    return res;}