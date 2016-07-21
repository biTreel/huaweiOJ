#include <iostream>
#define maxNum 20480
using namespace std;
int main()
{
   int N;
   int cnt=0;
   cin>>N;
   int chorus[maxNum]={0};
   for(int i=0;i!=N;++i)
       cin>>chorus[i];
   int largIndex=0;
   for(int i=0;i!=N;++i)
       if(chorus[i]>chorus[largIndex])
           largIndex=i;
   if(largIndex==0)
   {
       for(int i=0;i!=N-1;++i)
           if(chorus[i]<=chorus[i+1])
               ++cnt;
   }
    else if(largIndex==N-1)
    {
        for(int i=0;i!=N-1;++i)
            if(chorus[i]>=chorus[i+1])
                ++cnt;
    }
    else
    {
        for(int i=0;i!=largIndex;++i)
        {
            if(chorus[i]>=chorus[i+1])
                ++cnt;
        }
        for(int i=largIndex;i!=N-1;++i)
        {
            if(chorus[i]<=chorus[i+1])
                  ++cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
