
#include <iostream>
#include <string>

using namespace std;

int calcCapital(string str);
int main()
{
    string str;
    getline(cin,str);
    int cnt=calcCapital(str);
    cout<<cnt<<endl;
    return 0;
}

int calcCapital(string str)
{
    if(str.empty())
        return 0;
    int cnt=0;
    string::iterator iter=str.begin();
    for(;iter!=str.end();++iter)
        if('A'<=*iter && *iter<='Z')
            ++cnt;
    return cnt;
}
