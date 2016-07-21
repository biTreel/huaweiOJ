//计负均正(中)

#include <iostream>
#include <vector>
//#include <cstdio>
#include <iomanip>

using namespace  std;

int main(int argc,char** argv)
{
    int val;
    int cnt=0;
    vector<int> ivec;
    //cin>>val;
    while(cin>>val)
    {
        if(val<0)
            ++cnt;
        else
            ivec.push_back(val);
        //cin>>val;
    }
    cout<<cnt<<endl;
    size_t sum=0;
    float average=0.0;
    if(0<ivec.size())
    {
        //size_t sum=0;
        //float average=0;
        vector<int>::iterator iter=ivec.begin();
        for(;iter!=ivec.end();++iter)
            sum+=*iter;
        average=(float)sum/ivec.size();
        cout<<fixed<<setprecision(1)<<average<<endl;
    }
    else
        cout<<fixed<<setprecision(1)<<average<<endl;
    return 0;
}
