#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    string::reverse_iterator riter=str.rbegin();
    for(;riter!=str.rend();++riter)
        cout<<*riter;
    cout<<endl;
    return 0;
}
