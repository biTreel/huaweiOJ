/*
 * Author: biTree
 * Date: June,11,2016
 */

#include <iostream>
#include <string>
#include <cstring>
//#define MAX 2048
using namespace std;
void reverse(char* p,char* q);
int MarkNum(char* pInStr,char* pOutStr);
int main(){
    string str;
    char *inStr=new char,*outStr=new char;
    getline(cin,str);
    strcpy(inStr,str.c_str());
    MarkNum(inStr,outStr);

    int i=0;
    while(inStr[i]!='\0'){
        cout<<inStr[i++];
    }
    /*
    i=0;
    while(outStr[i]!='\0'){
        cout<<outStr[i];
        ++i;
    }
    */
    delete inStr;
    delete outStr;
    return 0;
}

void reverse(char* p,char* q){
    /*
    char* p=s;
    char* q=s;
    while(*q)
        q++;
    q--;
    */
    char tmp;
    while(p<q){
        tmp=*p;
        *p++=*q;
        *q--=tmp;
        //++p;
        //--q;
    }
}

int MarkNum(char* pInStr,char* pOutStr){
    if(pInStr==NULL)
        return -1;
    //pOutStr=new char;
    char* p=pInStr;
    char* q=pInStr;
    while(*q!='\0'){
        if(*q==' '){
            reverse(p,q-1);
            q++;
            p=q;
        }
        else
            q++;
    }
    reverse(p,q-1); 
    reverse(pInStr,q-1);
    //pOutStr=pInStr;
    //delete pOut
    return 0;
}
