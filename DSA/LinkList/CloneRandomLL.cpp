#include<iostream>
#include<unordered_map>
using namespace std;

typedef class Node{
    public:
    int data;
    class Node *next;
    class Node *rand;

    Node(int data)
    {
        this->data=data;
        next = NULL;
        rand = NULL;
    }
}NODE, * PNODE;

void InsertFirst(PNODE &Head, int val)
{
    PNODE newn = new NODE(val);

    if(Head == NULL)
        Head = newn;
    else
    {
        newn->next = Head;
        Head = newn;
    }
}

void InsertLast(PNODE &Head, PNODE &Tail, int val)
{
    PNODE newn = new NODE(val);

    if(Head == NULL)
    {
        Head = Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        cout<<Head->data<<" -> ";
        Head = Head -> next;
    }
}

// Approach-1
PNODE CloneIt(PNODE OldLL)
{
    unordered_map<PNODE,PNODE> linking;
    PNODE NewLL = NULL;
    PNODE Tail = NULL;
    PNODE temp = OldLL;

    while(temp != NULL)
    {
        InsertLast(NewLL, Tail, temp->data);
        linking[temp] = Tail;
        temp = temp -> next;
    }

    temp = OldLL;
    PNODE tempNew = NewLL;

    while(temp!=NULL)
    {
        tempNew -> rand = linking[temp -> rand];
        temp = temp->next;
        tempNew = tempNew -> next;
    }

    return NewLL;
}

// Approach-2
PNODE CloneIt_2(PNODE Head)
{
    if(Head == NULL)
        return NULL;

    PNODE temp = Head;
    PNODE newHead = NULL;
    PNODE Tail = NULL;
    
    // CLONING
    while(temp!=NULL)
    {
        InsertLast(newHead, Tail, temp->data);
        temp = temp -> next;
    }

    // LINKING
    temp = Head;
    PNODE newTemp = newHead;
    while(temp != NULL)
    {
        PNODE nextNODE = temp->next;
        temp->next = newTemp;
        temp = nextNODE;

        nextNODE = newTemp -> next;
        newTemp -> next = temp;
        newTemp = nextNODE;
    }

    // Random pointer setting
    temp = Head;
    newTemp = newHead;
    while(temp != NULL)
    {
        if(temp->rand != NULL)
            newTemp->rand = temp->rand->next;
        else
            newTemp -> rand = NULL;

        temp = temp -> next -> next;
        newTemp = newTemp -> next; //*
    }

    temp = Head;
    newTemp = newHead; 
    while(temp != NULL && newTemp != NULL)
    {
        temp -> next = newTemp->next;
        temp = temp->next;

        if(temp != NULL)
            newTemp->next = temp->next;
        newTemp = newTemp -> next;
    }

    return newHead;
}

int main()
{
    PNODE Head = NULL;
    PNODE newHead = NULL;

    InsertFirst(Head, 30);
    InsertFirst(Head, 25);
    Head -> next -> rand = Head;
    InsertFirst(Head, 20);
    Head -> rand = Head -> next -> next;
    InsertFirst(Head, 15);
    InsertFirst(Head, 10);
    Head -> rand = Head -> next -> next;
    InsertFirst(Head, 5);
    Head->next->next->next->rand = Head;
    Head->rand = Head->next->next;

    // CloneIt(newHead, Head);

    // cout<<Head->rand->data<<endl;
    // cout<<newHead->rand->data<<endl; 

    cout<<Head->rand->data<<endl;
    Head = CloneIt_2(Head);
    cout<<Head->rand->data<<endl;

    // Display(Head);
    return 0;
}