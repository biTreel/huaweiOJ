#include <iostream>
#include <string>

using namespace std;

void insertSort(string& str);
int main(int argc,char** argv)
{
    string str;
    getline(cin,str);
    cout<<"before sort: ";
    string::iterator it=str.begin();
    for(;it!=str.end();++it)
        cout<<*it;
    insertSort(str);
    cout<<"\nafter sort: ";
    it=str.begin();
    for(;it!=str.end();++it)
        cout<<*it;
    return 0;

}

void insertSort(string& str)
{
    for(int p=1;p!=str.size();++p)
    {
        char tmp=str[p];
        int j=p;
        for(;j>0 && tmp<str[j-1];--j)
            str[j]=str[j-1];
        str[j]=tmp;
    }
}
