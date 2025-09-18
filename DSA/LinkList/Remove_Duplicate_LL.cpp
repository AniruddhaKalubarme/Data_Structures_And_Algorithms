#include<iostream>
#include<map>
using namespace std;

typedef class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
}NODE, *PNODE;

void InsertLast(PNODE &Head, PNODE &Tail, int data)
{
    PNODE newn = new NODE(data);
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
    if(Head == NULL)
        return;

    while(Head != NULL)
    {
        cout<<Head->data<<" -> ";
        Head = Head -> next;
    }
}

void Remove_Duplicate_Sorted(PNODE Head)
{
    if(Head == NULL) return;

    while(Head->next != NULL)
    {
        if(Head -> data == Head -> next -> data)
        {
            PNODE temp = Head->next;
            Head->next = Head->next->next;
            delete temp;
            continue;
        }
        Head = Head->next;
    }
}

// Approach - 1
void Remove_Duplicate_Unsorted(PNODE Head)
{
    if(Head == NULL)
        return;

    PNODE Head1 = Head;

    while(Head1->next != NULL)
    {
        int data = Head1->data;
        PNODE Head2 = Head1;

        while(Head2->next != NULL)
        {
            if(Head2->next->data == data)
            {
                PNODE temp = Head2->next;
                Head2 -> next = temp->next;
                delete temp;
                continue;
            }
            Head2 = Head2->next;
        }
        Head1 = Head1 -> next;
    }
}

// Approach - 2
/*
1) Sort the link-list
2) Call the function Remove_Duplicate_Sorted
*/

// Approach - 3
void Remove_Duplicate_Unsorted_Using_Map(PNODE Head)
{
    if(Head == NULL) return;

    map <int, bool> Visited;
    PNODE forward = Head->next;
    while(forward != NULL)
    {
        Visited[Head->data] = true;
        if(Visited[forward->data] == true)
        {
            PNODE temp = forward;
            forward = forward->next;
            delete temp;
            Head->next = forward;
            continue;
        }
        forward = forward->next;
        
        Head = Head->next;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertLast(Head, Tail, 5);
    InsertLast(Head, Tail, 10);
    InsertLast(Head, Tail, 5);
    InsertLast(Head, Tail, 25);
    InsertLast(Head, Tail, 15);
    InsertLast(Head, Tail, 15);
    InsertLast(Head, Tail, 20);
    InsertLast(Head, Tail, 25);
    InsertLast(Head, Tail, 15);
    InsertLast(Head, Tail, 30);
    InsertLast(Head, Tail, 20);


    Display(Head);
    Remove_Duplicate_Unsorted_Using_Map(Head);
    cout<<endl;
    Display(Head);
    return 0;
}
