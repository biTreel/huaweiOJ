#include <iostream>
#include <map>
#include <string>
//#define MAX 10240

bool FindChar(char* pInputString,char* pChar);
using namespace std;
int main()
{
    char pc;
    string str;
    char *pstr;
    //cin>>str;
    getline(cin,str);
    pstr=new char[str.size()+1];
    str.copy(pstr,str.size(),0);
    /*
    int i=0;
    do
    {
        cout<<pstr[i++];
    }while(pstr[i]!='\0');
    */
    bool tk=FindChar(pstr,&pc);
    if(tk)
        cout<<pc<<endl;
    else
        cout<<'.'<<endl;
    delete [] pstr;
    return 0;

}

bool FindChar(char* pInputString,char* pChar)
{
    bool taken=false;
    int i=0;
    map<char,int> mp;
    do
    {
        ++mp[pInputString[i++]];
    }while(pInputString[i]!='\0');
    map<char,int>::iterator iter=mp.begin();
    for(; iter!=mp.end();++iter)
    {
        if(iter->second==1)
        {
            *pChar=iter->first;
            taken=true;
            break;
        }
    }
    return taken;
}


