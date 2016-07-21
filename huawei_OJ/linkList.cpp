/*
 *Author: biTree
 *Date: Apr 12,2016
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
    ListNode():m_pNext(NULL){}
};

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k);

int main()
{
    int n;
    cin>>n;
    if(n==0)
        return -1;

    ListNode* head=new ListNode;
    int key;
    head->m_nKey=n; //store the number of link.
    ListNode* p=head;
    int i=0;
    while(i!=n)
    {
        ListNode* curr=new ListNode;
        cin>>key;
        curr->m_nKey=key;
        p->m_pNext=curr;
        p=curr;
        ++i;
    }
    //head=head->m_pNext;
    p->m_pNext=NULL;
    //test
    /*
    ListNode* temp=head;
    while(temp!=NULL)
    {
       cout<<temp->m_nKey<<" ";
       temp=temp->m_pNext;
    }
    cout<<endl;
    */
    int k;
    cin>>k;
    ListNode* pKth=FindKthToTail(head,k);
    if(pKth)
        cout<<pKth->m_nKey<<endl;
    return 0;
}

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
    if(pListHead==NULL)
        return NULL;

    ListNode* pa=pListHead;
    ListNode* pb=pListHead;
    while(k--)
    {
        if(pa->m_pNext!=NULL)
            pa=pa->m_pNext;
        else
            return NULL;
       // cout<<pa->m_nKey<<endl;
       // --k;
    }
    while(pa->m_pNext!=NULL)
    {
        pa=pa->m_pNext;
        pb=pb->m_pNext;
    }
    //cout<<"pa: "<<pa->m_nKey<<", pb: "<<pb->m_nKey<<endl;
    return pb;
}


