/*
 * Author: biTree
 * Date: May 29 ,2016
 */
#include <iostream>
using namespace std;
//#define uint (unsigned int )

bool GetMinK(unsigned int uiInputNum,int* pInputArr,
        unsigned int uiK,int* pOutputArr);
void insertSort(int* inputArr,unsigned int n);
int main()
{
    int n,k;
    cin>>n>>k;
    int* inputArr=new int [n];
    int* outputArr=new int[k];
    int val,i=0;
    while(i!=n && cin>>val)
    {
        //++i;
        inputArr[i]=val;
        ++i;
    }
    if(GetMinK(n,inputArr,k,outputArr))
    {
        for(int i=0;i!=k;++i)
            cout<<outputArr[i];
        cout<<endl;
    }
    delete [] inputArr;
    delete [] outputArr;
    return 0;
}

bool GetMinK(unsigned int uiInputNum,int* pInputArr,
        unsigned int uiK,int* pOutputArr)
{
    bool flag=false;
    //int* tmp=pInputArr;
    insertSort(pInputArr,uiInputNum);
    if(0<uiK && uiK<=uiInputNum)
    {
        flag=true;
        for(unsigned int i=0;i!=uiK;++i)
            pOutputArr[i]=pInputArr[i];
    }
    return flag;
}

void insertSort(int* inputArr,unsigned int n)
{
    for(unsigned int p=1;p!=n;++p)
    {
        int tmp=inputArr[p];
        int i=p;
        for(;0<i && tmp<inputArr[i-1];--i)
            inputArr[i]=inputArr[i-1];
        inputArr[i]=tmp;
    }
}

