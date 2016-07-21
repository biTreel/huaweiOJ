/*
 * Author: biTree
 * Date: June,15,2016
 */

#include <iostream>
using namespace std;
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};
void create(ListNode *h,int cnt);
ListNode *del(ListNode *h,int v);
void print(ListNode *h);
int main(int argc,char** argv){
    int cnt,hv;
    ListNode *head=new ListNode;
    cin>>cnt>>hv;
    head->m_nKey=hv;
    head->m_pNext=NULL;
    create(head,cnt);
    //print(head);
    //cout<<"\ninput del val:"<<endl;
    int dv;
    cin>>dv;
    head=del(head,dv);
    print(head);
    return 0;
}
void create(ListNode* h,int cnt){
    if(cnt<=0)
        return;
    int val,pos;
    ListNode *p,*s;
    p=h;
    while(--cnt){
        cin>>val>>pos;
        while(p!=NULL){
            if(p->m_nKey==pos){
                s=new ListNode;
                s->m_nKey=val;
                //insert after p
                s->m_pNext=p->m_pNext;
                p->m_pNext=s;
                break;
            }
            else
                p=p->m_pNext;
        }
        p=h; //fronm begin
        
    }
}

ListNode *del(ListNode *h,int v){
    ListNode *p=h,*t;
    while(p->m_nKey!=v && p->m_pNext!=NULL){
        t=p;
        p=p->m_pNext;
    }
    if(p->m_nKey==v){
        if(p==h){
            h=h->m_pNext;
        }
        else if(p->m_pNext==NULL){
            t->m_pNext=NULL;
        }
        else{
            t->m_pNext=p->m_pNext;
        }
        delete p;
    }
    else
        return NULL;
    return h;
}

void print(ListNode *h){
    if(NULL==h)
        return;
    ListNode *p=h;
    while(p->m_pNext!=NULL){
        cout<<p->m_nKey;
        p=p->m_pNext;
    }
    cout<<p->m_nKey;
    cout<<endl;
}
