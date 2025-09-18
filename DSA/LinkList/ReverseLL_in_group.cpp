#include<iostream>
using namespace std;

typedef class NODE{
    public:
    int data;
    NODE *next;

    NODE(int data)
    {
        this->data = data;
        next = NULL;
    }
}NODE, * PNODE;

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

PNODE ReverseParticular(PNODE Head, int k)
{
    if(Head == NULL)
        return NULL;

    PNODE curr = Head;
    PNODE prev = NULL;
    PNODE next = NULL;

    int iCnt = 0;

    while(curr != NULL && iCnt++<k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    if(next != NULL)
        Head -> next = ReverseParticular(next, k);
    
    return prev;
    
}

bool IsCircular(PNODE Head)
{
    if(Head == NULL || Head->next == Head)
        return true;
    
    PNODE temp = Head;
    do{
        Head = Head->next;
    }while(Head != NULL && Head != temp);

    if(Head == NULL)
        return false;
    else
        return true;
}

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        cout<<Head->data<<" -> ";
        Head = Head->next;
    }
}

int main()
{
    PNODE Head = NULL;
    // PNODE Tail = NULL;
    InsertFirst(Head, 30);
    InsertFirst(Head, 25);
    InsertFirst(Head, 20);
    InsertFirst(Head, 15);
    InsertFirst(Head, 10);
    InsertFirst(Head, 5);

    // Tail->next = Head;
    Head = ReverseParticular(Head, 2);
    Display(Head);

    
    if(IsCircular(Head))
        cout<<"Circular LL";
    else
        cout<<"Linear LL";
    return 0;
}