#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;
//void insertSort(map<char,int>&);
class cmpByVal
{
    public:
        bool operator()(const pair<char,int>&lhs,const pair<char,int>&rhs)
        {
            return lhs.second > rhs.second;
        }
};

int main()
{
    map<char,int> cmap;
    string str;
    getline(cin,str);
    string::iterator strIter=str.begin();
    for(;strIter!=str.end();++strIter)
    {
        //test
        //cout<<*strIter;
        if(isalpha(*strIter))
            ++cmap[*strIter];
        else if(isdigit(*strIter))
            ++cmap[*strIter];
        else if(' '==*strIter)
            ++cmap[*strIter];
        else
            ;
    }
    vector< pair<char,int> > toVect(cmap.begin(),cmap.end());
    sort(toVect.begin(),toVect.end(),cmpByVal());
    //test
    //insertSort(cmap);
    //cout<<endl;
    vector< pair<char,int> >::iterator iter=toVect.begin();
    for(;iter!=toVect.end();++iter)
        cout<<iter->first;
    
    return 0;
}


