#include <iostream>
using namespace std;
typedef struct  node
{
    int nodevalue;
    struct node *next;
}node, linklist;
//为了得到倒数第k个结点，很自然的想法是先走到链表的尾端，再从尾端回溯k步。
//可是输入的是单向链表，只有从前往后的指针而没有从后往前的指针。
//在遍历时维持两个指针，第一个指针从链表的头指针开始遍历，在第k-1步之前，第二个指针保持不动；在第k-1步开始，
//第二个指针也开始从链表的头指针开始遍历。由于两个指针的距离保持在k-1，
//当第一个（走在前面的）指针到达链表的尾结点时，第二个指针（走在后面的）指针正好是倒数第k个结点。
linklist *BuildList( int m)
{
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->nodevalue=m;//第一个存放结点个数
    linklist *t = head;
    if (head)
    {
        for (int i = 0; i < m ; i++)
        {
            node *nextnode = (node *)malloc(sizeof(node));
            nextnode->next = NULL;//新建节点  
            cin >> nextnode->nodevalue;//  
            head->next = nextnode;
            head = nextnode;
        }
    }
    else
    {
        cout << "head new comes error!" << endl;
    }
    return t;

}
linklist* FindKthToTail_Solution2(linklist *pListHead, unsigned int k)
{
    
    if (pListHead == NULL)
        return NULL;

    linklist *pAhead = pListHead;
    linklist *pBehind = NULL;
    
    for (unsigned int i = 0; i < k; i++)
    {
        if (pAhead->next  != NULL)//尼玛，要从倒数第0个开始算起！！！！
            pAhead = pAhead->next;
        else
        {
            // if the number of nodes in the list is less than k, 
            // do nothing
            return NULL;
        }
    }

    pBehind = pListHead;

    // the distance between pAhead and pBehind is k
    // when pAhead arrives at the tail, p
    // Behind is at the kth node from the tail
    while (pAhead->next!= NULL)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    return pBehind;
}
int main()
{
    int nodenum;
    cin >> nodenum;
    linklist *p;
    p = BuildList(nodenum);
    int k;
    cin >> k;
    linklist *resu = FindKthToTail_Solution2(p->next,k);
    cout << resu->nodevalue << endl;

    return 1;
}
