//记负均正(初)
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int main(int argc,char** argv)
{
    int n;
    //int* iarr;
    vector<int> ivec;
    int i=0;
    int cnt=0;
    int val;
    cin>>n;
    while(i++!=n && cin>>val)
    {
        if(0<val)
            ivec.push_back(val);
        else
            ++cnt;
    }
    cout<<cnt<<endl;
    long sum=0;
    float average=0.0;
    if(0<ivec.size())
    {
        //cout<<cnt<<endl;
        //long sum=0;
        //float average=0;
        vector<int>::iterator iter=ivec.begin();
        for(;iter!=ivec.end();++iter)
            sum+=*iter;
        average=(float)sum/ivec.size();
        if((int)average==average)
            cout<<average<<endl;
        else
            cout<<fixed<<setprecision(1)<<average<<endl;
    }
    else
        cout<<average<<endl;
    return 0;
}
