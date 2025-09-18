#include<iostream>
using namespace std;

typedef class node
{
    public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
}NODE, * PNODE;


class Singly
{
    public:
    PNODE Head;

    Singly()
    {
        Head = NULL;
    }

    void InsertFirst(int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn -> next = Head;
            Head = newn;
        }
    }

    void ReverseLL()
    {
        if(Head == NULL || Head -> next == NULL)
            return;
        else
        {
            PNODE prev = NULL;
            PNODE current = Head;
            PNODE nextNODE = NULL;
            while(current != NULL)
            {
                nextNODE = current->next;
                current->next = prev;
                prev = current;
                current = nextNODE;
            }
            Head = prev;
        }
    }

    void ReverseLL_Recursion(PNODE current, PNODE prev = NULL)
    {
        if(current == NULL)
        {
            Head = prev;
            return;
        }

        ReverseLL_Recursion(current->next, current);
        current->next = prev;
    
    }

    PNODE ReverseLL_Recursion_2(PNODE Head)
    {
        if(Head == NULL || Head -> next == NULL)
        {
            return Head;
        }

        PNODE ChotaHead = ReverseLL_Recursion_2(Head->next);
        Head->next->next = Head;
        Head -> next = NULL;

        return ChotaHead;
    }

    void Display()
    {
        PNODE Temp = Head;
        while(Temp != NULL)
        {
            cout<<Temp->data<<" -> ";
            Temp = Temp->next;
        }
    }
};

int main()
{
    Singly obj;
    obj.InsertFirst(15);
    obj.InsertFirst(10);
    obj.InsertFirst(5);
    obj.InsertFirst(4);
    obj.InsertFirst(3);

    obj.Display();
    // obj.ReverseLL();
    cout<<endl;
    obj.Head = obj.ReverseLL_Recursion_2(obj.Head);
    obj.Display();

    return 0;
}