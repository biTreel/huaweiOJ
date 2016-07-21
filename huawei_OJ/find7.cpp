#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <cstdlib>
//#include <stdllib.h>

using namespace std;
void find7(int n);

int main()
{
    int N;
    do
    {
        cin>>N;
    }
    while((30000<N) || (N<1));
    find7(N);
    return 0;
}

void find7(int n)
{
    int cnt=0;
    vector<int> ivec;
    vector<string> svec;
    string str;
    //stringstream ss;
    for(int i=6;i!=n;++i)
        ivec.push_back(i);
    vector<int>::iterator iter=ivec.begin();
    for(;iter!=ivec.end();++iter)
    {
        //cout<<*iter<<" ";
        
        if(*iter%7==0)
        {
            ++cnt;
            //ivec.erase(iter);
        }
        else
        {
            //cout<<*iter<<" ";
         //itoa(*iter,str,10);
            //str=to_string(*iter);   //c++11
            stringstream ss;
            ss<<*iter;
            str=ss.str();
            //cout<<"("<<str<<") ";
            svec.push_back(str);
        }  
    }
    vector<string>::iterator it=svec.begin();
    for(;it!=svec.end();++it)
    {
        str=*it;
        string::iterator is=str.begin();
        for(;is!=str.end();++is)
        {
            if(*is=='7')
            {
                ++cnt;
                break;
            }
        }
    }

    cout<<cnt<<endl;
    
}


