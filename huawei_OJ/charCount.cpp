#include <iostream>
#include <string>
using namespace std;
int getEnglishCharCount(string str)
{
    int cnt=0;
    string::iterator iter=str.begin();
    for(;iter!=str.end();++iter)
        if(isalpha(*iter))
                ++cnt;
    return cnt;
}

int getBlankCharCount(string str)
{
    int cnt=0;
    string::iterator iter=str.begin();
    for(;iter!=str.end();++iter)
        if(' '==*iter)
            ++cnt;
    return cnt;
}

int getNumberCharCount(string str)
{
    int cnt=0;
    string::iterator iter=str.begin();
    for(;iter!=str.end();++iter)
        if(isdigit(*iter))
            ++cnt;
    return cnt;
}

int getOtherCharCount(string str)
{
    int cnt=0;
    string::iterator iter=str.begin();
    for(;iter!=str.end();++iter)
    {
        if(isalpha(*iter))
            continue;
        else if(isdigit(*iter))
            continue;
        else if(' '==*iter)
            continue;
        else
            ++cnt;
        //return cnt;
    }
    return cnt;
}

int main(int argc,char** argv)
{
    string str;
    getline(cin,str);
    int charNum=getEnglishCharCount(str);
    cout<<charNum<<endl;
    int blankNum=getBlankCharCount(str);
    cout<<blankNum<<endl;
    int digitNum=getNumberCharCount(str);
    cout<<digitNum<<endl;
    int otherNum=getOtherCharCount(str);
    cout<<otherNum<<endl;
    
    return 0;
}


