#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class cmpByVal
{
    public:
        bool operator()(const pair<char,int>& lhs,
                const pair<char,int>& rhs)
        {
            return lhs.second>rhs.second;
        }
};

void getBeautyName(int n);
int main()
{
    int N;
    cin>>N;
    getBeautyName(N);

    return 0;
}

void getBeautyName(int n)
{
    string name;
    map<char,int> charNum;
    vector< pair<char,int> > vectMap;
    for(int i=0;i!=n;++i)
    {
        cin>>name;
        int beautyVal=0;
        string::iterator iter=name.begin();
        for( ; iter!=name.end() ;++iter )
        {
            if(isalpha(*iter))
            {
                if(isupper(*iter))
                    tolower(*iter);
                ++charNum[*iter];
            }
        }
        map<char,int>::iterator mapIt=charNum.begin();
        for(; mapIt!=charNum.end();++mapIt)
            vectMap.push_back(*mapIt);
        sort(vectMap.begin(),vectMap.end(),cmpByVal());
        
        vector< pair<char,int> >::iterator it=vectMap.begin();
        for(int i=26; it!=vectMap.end();++it,--i)
        {
            beautyVal+=(*it).second * i;
        }
        cout<<beautyVal<<endl;
        name.clear();
        charNum.clear();
        vectMap.clear();
    }
    //cout<<endl;
}


