#include<iostream>
#include<map>

using namespace std;
typedef class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        next = NULL;
        this->data = data;
    }
}NODE, * PNODE;

// Approach-1
bool IsLoop(PNODE Head)
{
    map <PNODE , bool> Visited;

    while(Head != NULL)
    {
        if(Visited[Head] ==  true)
            return true;

        Visited[Head] = true;
        Head = Head -> next;
    }

    return false;
}

// Approach-2
bool IsLoop_2(PNODE Head)
{
    PNODE slow = Head;
    PNODE fast = Head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow)
            return true;
    }

    return false;
}

//-------------------------------------------------------------------------------
PNODE Intersection_NODE(PNODE Head)
{
    PNODE slow = Head;
    PNODE fast = Head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow)
            return fast;
    }
}

PNODE Find_the_Looping_NODE(PNODE Head)
{
    PNODE Intersection = Intersection_NODE(Head);

    PNODE slow = Head;
    while(slow != Intersection)
    {
        slow = slow->next;
        Intersection = Intersection->next;
    }

    cout<<"Intersection at: "<<Intersection->data<<endl;
    return Intersection;
}
//---------------------------------------------------------------------------------

void End_the_LOOP(PNODE Head)
{
    PNODE Intersection = Intersection_NODE(Head);
    PNODE LOOP = Find_the_Looping_NODE(Head);

    while(Intersection->next != LOOP)
    {
        Intersection = Intersection->next;
    }

    Intersection->next = NULL;

}

void InsertFirst(PNODE &Head, PNODE &Tail, int data)
{
    PNODE newn = new NODE(data);
    if(Head == NULL)
        Head = Tail = newn;
    else
    {
        newn -> next = Head;
        Head = newn;
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

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertFirst(Head, Tail, 30);
    InsertFirst(Head, Tail, 25);
    InsertFirst(Head, Tail, 20);
    InsertFirst(Head, Tail, 15);
    InsertFirst(Head, Tail, 10);
    InsertFirst(Head, Tail, 5);

    Tail -> next = Head -> next -> next;
    // cout<<Tail->next->data<<endl;
    
    /*
    bool chk = IsLoop_2(Head);
    if(chk)
        cout<<"!! LOOP IS PRESENT !!"<<endl;
    else
        cout<<"LOOP IS NOT PRESENT"<<endl;
    */

    // Find_the_Looping_NODE(Head);

    End_the_LOOP(Head);
    Display(Head);
    return 0;
}