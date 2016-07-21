#include <iostream>

using namespace std;

void combineBySort(int* pArr1,int num1,int* pArr2,int num2,
        int* pOutArr,int* outNum);

void insertSort(int* arr,int num);
bool find(const int* arr,int num,const int val);
int main()
{
    //int* pArr1,*pArr2,*pOutArr;
    int num1,num2;
    cin>>num1;
    int* pArr1=new int[num1];
    int i=0;
    while(i!=num1)
        cin>>pArr1[i++];
   /* 
    for(int j=0;j!=num1;++j)
        cout<<pArr1[j]<<" ";
    cout<<"\num2:"<<endl;
    */
    cin>>num2;
    int* pArr2=new int[num2];
    i=0;
    while(i!=num2)
        cin>>pArr2[i++];
    /*
    for(int j=0;j!=num2;++j)
        cout<<pArr2[j]<<" ";
    cout<<endl;
    */
    insertSort(pArr1,num1);
    insertSort(pArr2,num2);

    int* outNum=new int;
    int* pOutArr=new int[num1+num2];
    combineBySort(pArr1,num1,pArr2,num2,pOutArr,outNum);
    for(int i=0;i!=*outNum;++i)
        cout<<pOutArr[i];
    cout<<endl;
    
    delete outNum;
    delete [] pArr1;
    delete [] pArr2;
    delete [] pOutArr;

    return 0;
}

void combineBySort(int* pArr1,int num1,int* pArr2,int num2,
        int* pOutArr,int* outNum)
{
    int pos1=0;
    int pos2=0;
    int posOut=0;
    /*
    insertSort(pArr1,num1);
    cout<<"insertSort:"<<endl;
    for(int i=0;i!=num1;++i)
        cout<<pArr1[i]<<" ";
    cout<<endl;
    insertSort(pArr2,num2);
    for(int i=0;i!=num2;++i)
        cout<<pArr2[i]<<" ";
    cout<<endl;
    */
    while(pos1<=num1-1 && pos2<=num2-1)
    {
        if(pArr1[pos1]<=pArr2[pos2])
        {
            if(find(pOutArr,posOut,pArr1[pos1]))
            {
                ++pos1;
                continue;
            }
            pOutArr[posOut]=pArr1[pos1];
            ++posOut;
            ++pos1;
        }
        else
        {
            if(find(pOutArr,posOut,pArr2[pos2]))
            {
                ++pos2;
                continue;
            }
            pOutArr[posOut]=pArr2[pos2];
            ++posOut;
            ++pos2;
        }
            
    }
    while(pos1<=num1-1)
    {
        if(find(pOutArr,posOut,pArr1[pos1]))
        {
            ++pos1;
            continue;
        }
        pOutArr[posOut]=pArr1[pos1];
        ++pos1;
        ++posOut;
    }
    while(pos2<=num2-1)
    {
        if(find(pOutArr,posOut,pArr2[pos2]))
        {
            ++pos2;
            continue;
        }
        pOutArr[posOut]=pArr2[pos2];
        ++pos2;
        ++posOut;
    }
    *outNum=posOut;
}

void insertSort(int* arr,int num)
{
    for(int p=1;p!=num;++p)
    {
        int tmp=arr[p];
        int j=p;
        for(;j>0 && tmp<arr[j-1];--j)
            arr[j]=arr[j-1];
        arr[j]=tmp;
    }
}

bool find(const int* arr,int num,const int val)
{
    bool taken=false;
    for(int i=0;i!=num;++i)
        if(val==arr[i])
            taken=true;
    return taken;
}



