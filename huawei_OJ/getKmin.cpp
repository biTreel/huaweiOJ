/*get K min in N
 *Author: biTree
 *Date May 28,2016
 */
#include <iostream>
#include <vector>
using namespace std;
/*
void quickSort(vector<int>& ivec);  //driver function*
void quickSort(vector<int>& ivec,size_t left,size_t right);
int median3(vector<int>& ivec,size_t left,size_t right);
*/
void insertSort(vector<int>& ivec);
void getKmin(vector<int>& inputVec,vector<int>& outputVec,int k);
int main(int argc,char** argv)
{
    int n,k;
    vector<int> inputVec,outputVec;
    cin>>n>>k;
    int val,i=0;
    while(i++!=n && cin>>val)
        inputVec.push_back(val);
    getKmin(inputVec,outputVec,k);
    vector<int>::iterator iter=outputVec.begin();
    for(;iter!=outputVec.end();++iter)
        cout<<*iter;
    cout<<endl;
    return 0;
}

void getKmin(vector<int>& inputVec,vector<int>& outputVec,int k)
{
    //quickSort(inputVec);
    insertSort(inputVec);
    if(0<k && k<inputVec.size())
    {
        int i=0;
        while(i!=k)
        {
            outputVec.push_back(inputVec[i]);
            ++i;
        }
    }
    else
        cout<<"error"<<endl;
}
/*
void quickSort(vector<int>& ivec)
{
    quickSort(ivec,0,ivec.size()-1);
}

void quickSort(vector<int>& ivec,size_t left,size_t right)
{
    if(left+10<right)
    {
        int pivot=median3(ivec,0,ivec.size()-1);
        int i=left,j=right-1;
        while(i<j)
        {
            while(ivec[++i]<pivot);
            while(pivot<ivec[--j]);
            swap(ivec[i],ivec[j]);
        }
        swap(ivec[i],ivec[right-1]);
        quickSort(ivec,left,i-1);
        quickSort(ivec,i,right);
    }
    else
        insertSort(ivec);
}

int median3(vector<int>& ivec,size_t left,size_t right)
{
    size_t center=(left+right)/2;
    if(ivec[center]<ivec[left])
        swap(ivec[center],ivec[left]);
    if(ivec[right]<ivec[left])
        swap(ivec[right],ivec[left]);
    if(ivec[right]<ivec[center])
        swap(ivec[right],ivec[center]);
    swap(ivec[center],ivec[right-1]);
    return ivec[right-1];   //pivot
}
*/
void insertSort(vector<int>& ivec)
{
    for(size_t p=1;p!=ivec.size();++p)
    {
        int tmp=ivec[p];
        size_t i=p;
        for(;i>0 && tmp<ivec[i-1];--i)
            ivec[i]=ivec[i-1];
        ivec[i]=tmp;
    }
}
