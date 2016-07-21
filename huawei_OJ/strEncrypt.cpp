#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;
void Encrypt(char aucPassword[],char aucResult[]);
void unEncrypt(char result[],char password[]);
int main()
{
    string str;
    char toPass[100];
    char aucResult[100];
    char unPass[100];
    char c1,c2;
    int i=0,j=0;
    
    getline(cin,str);
    str.copy(toPass,str.size(),0);
    //str.clear();
    //getline(cin,str);
    //str.copy(aucResult,str.size(),0);
    /*
    while(cin.get(c1) && i!=100)
    {
        //cin.get(c);
        toPass[i]=c1;
        ++i;
    }
    while(cin.get(c2) && j!=100)
    {
        unPass[j]=c2;
        ++j;
    }
    */
    toPass[str.size()]='\0';
   while(toPass[i]!='\0')
   {
        cout<<toPass[i];
        ++i;
   }
   cout<<endl;
    Encrypt(toPass,aucResult);
    int k=0;
    while(aucResult[k] !='\0')
    {
        cout<<aucResult[k];
        ++k;
    }
    cout<<endl;
    
    return 0;
}

void Encrypt(char aucPassword[],char aucResult[])
{
    int i=0;
    while(aucPassword[i] != '\0')
    {
        if(isalpha(aucPassword[i]))
        {
            if(isupper(aucPassword[i]))
            {
                if(aucPassword[i]=='Z')
                    aucResult[i]='a';
                else
                    aucResult[i]=tolower(aucPassword[i])+1;
            }
            else
            {
                if(aucPassword[i]=='z')
                    aucResult[i]='A';
                else 
                    aucResult[i]=toupper(aucPassword[i])+1;
            }
        }
        else if (isdigit(aucPassword[i]))
        {
            if(aucPassword[i]=='9')
                aucResult[i]='0';
            else
                aucResult[i]=aucPassword[i]+1;
        }
        else
            aucResult[i]=aucPassword[i];
        ++i;
    }
    aucResult[i]=='\0';
}


