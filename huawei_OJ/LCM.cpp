//最小公倍数--LCM
/*Author: biTree
 * Date: May 25,2016
 */

#include <iostream>
using namespace std;
typedef unsigned int uint;

uint LCM(uint,uint);
int main()
{
    uint a,b;
    cin>>a>>b;
    uint lcm=LCM(a,b);
    cout<<lcm<<endl;
    return 0;
}

uint LCM(uint a,uint b)
{
    uint tmpa=a;
    uint tmpb=b;
    uint c;
    while((c=tmpa%tmpb) != 0)
    {
        tmpa=tmpb;
        tmpb=c;
    }
    return a*b/tmpb;
}
