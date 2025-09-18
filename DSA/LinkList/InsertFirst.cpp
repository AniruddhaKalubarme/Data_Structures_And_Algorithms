#include<iostream>
using namespace std;

typedef class Node
{
    public:
    int data;
    Node *next;
    static int iCnt;
    Node(int data)
    {
        iCnt++;
        this->data = data;
        next = NULL;
    }
}NODE, * PNODE;

int NODE :: iCnt = 0;

int Count(PNODE Head)
{
    return NODE::iCnt;
}

void InsertFirst(PNODE &Head, int data)
{
    PNODE newn = new NODE(data);
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
}

void Display(PNODE Head)
{
    if(Head == NULL)
        return;

    while(Head->next != NULL)
    {
        cout<<Head->data<<" -> ";
        Head = Head -> next;
    }
    cout<<Head->data;
}