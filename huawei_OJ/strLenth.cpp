#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
        if(str.size()>128)
            getline(cin,str);
        int cnt=0;
        string::iterator iter=str.end();
     	for(;(--iter)>=str.begin();)
     	{
     		if(iter==(str.end()-1) && *iter==' ')
            {  
                str.erase(iter);
                continue;
            }
            if(*iter==' ')
                break;
            ++cnt;
     	}
        cout<<cnt<<endl;
    return 0;
}



