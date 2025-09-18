#include<iostream>
using namespace std;

typedef class Node
{
    public:
    static int iCnt;
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
        iCnt++;
    }
}NODE, * PNODE;

int NODE :: iCnt = 0;

class Singly{
    public:

    void InsertFirst(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }

    void InsertLast(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail->next = newn;
            Tail = Tail->next;
        }
    }

    void DeleteFirst(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;

        PNODE Temp = Head;

        Head = Head->next;
        free(Temp);
    }

    void DeleteLast(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;

        PNODE temp = Head;

        while(temp->next->next != NULL)
            temp = temp->next;

        free(temp->next);
        temp->next = NULL;
        Tail = temp;
    }

    void DeleteAtPos(PNODE &Head, PNODE &Tail, int iPos)
    {
        int iCnt = CountNode();
        if(Head == NULL || iPos < 1 || iPos > iCnt)
            return;
        else if(iPos == 1)
            DeleteFirst(Head, Tail);
        else if(iPos == iCnt)
            DeleteLast(Head, Tail);
        else
        {
            PNODE Temp = Head;
            for(int i = 1; i<iPos-1; i++)
                Temp = Temp->next;
            PNODE Del = Temp->next;
            Temp->next = Temp->next->next;
            free(Del);
        }
    }

    void InsertAtPos(PNODE &Head, PNODE &Tail, int data, int iPos)
    {
        PNODE temp = Head;
        int iCnt = CountNode();

        if(iPos > iCnt+1 || iPos < 1)
            return;

        if(iPos == 1)
            InsertFirst(Head, Tail, data);
        else if(iPos == iCnt+1)
            InsertLast(Head, Tail, data);
        else
        {
            PNODE newn = new NODE(data);
            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
        }  
    }

    int CountNode()
    {
        return NODE::iCnt;
    }

    void Display(PNODE Head)
    {
        PNODE temp = Head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
    }
    
};

class Dubbly{
    public:
    void InsertFirst(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = Tail = newn;
        }
        else
        {
            newn -> next = Head;
            Head -> prev = newn;
            Head = newn;
        }
    }

    void InsertLast(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
            Head = Tail = newn;
        else
        {
            newn->prev = Tail;
            Tail->next = newn;
            Tail = newn;
        }   
    }

    void InsertAtPos(PNODE &Head, PNODE &Tail, int data, int iPos)
    {
        int iCnt = CountNode();
        if(Head == NULL || iPos > iCnt+1 || iPos < 1)
            return;
        else if(iPos == 1)
            InsertFirst(Head, Tail, data);
        else if(iPos == iCnt+1)
            InsertLast(Head, Tail, data);
        else
        {
            PNODE newn = new NODE(data);
            PNODE temp = Head;
            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;

            newn->prev = temp;
            newn->next = temp->next;
            temp->next = newn;
            newn->next->prev = newn;
        }
    }

    void DeleteFirst(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;
        else
        {
            Head = Head->next;
            delete []Head->prev;
        }
    }

    void DeleteLast(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;
        else
        {
            Tail = Tail->prev;
            delete []Tail->next;
            Tail->next = NULL;
        }
    }

    void DeleteAtPos(PNODE &Head, PNODE &Tail, int iPos)
    {
        int iCnt = CountNode();
        if(Head == NULL || iPos <1 || iPos > iCnt)
            return;
        else if(iPos == iCnt)
            DeleteLast(Head, Tail);
        else if(iPos == 1)
            DeleteFirst(Head, Tail);
        else
        {
            PNODE temp = Head;
            // PNODE del;
            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;
            // del = temp;
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
        }
    }

    int CountNode()
    {
        return NODE::iCnt;
    }

    void Display(PNODE Head)
    {
        while(Head!=NULL)
        {
            cout<<Head->data<<" -> ";
            Head = Head->next;
        }
    }
};

class SinglyCircular{
    public:
    void InsertFirst(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
            Tail->next = Head;
        }
    }

    void InsertLast(PNODE &Head, PNODE &Tail, int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail->next = newn;
            Tail = Tail->next;
        }
        Tail->next = Head;
    }

    void DeleteFirst(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;

        NODE::iCnt--;
        PNODE Temp = Head;
        Head = Head->next;
        Tail->next = Head;
        free(Temp);
    }

    void DeleteLast(PNODE &Head, PNODE &Tail)
    {
        if(Head == NULL)
            return;

        NODE::iCnt--;
        PNODE temp = Head;
        while(temp->next->next != Head)
            temp = temp->next;

        free(temp->next);
        temp->next = Head;
        Tail = temp;
    }

    void DeleteAtPos(PNODE &Head, PNODE &Tail, int iPos)
    {
        int iCnt = CountNode();
        if(Head == NULL || iPos < 1 || iPos > iCnt)
            return;
        else if(iPos == 1)
            DeleteFirst(Head, Tail);
        else if(iPos == iCnt)
            DeleteLast(Head, Tail);
        else
        {
            NODE::iCnt--;
            PNODE Temp = Head;
            for(int i = 1; i<iPos-1; i++)
                Temp = Temp->next;
            PNODE Del = Temp->next;
            Temp->next = Temp->next->next;
            free(Del);
        }
    }

    void InsertAtPos(PNODE &Head, PNODE &Tail, int data, int iPos)
    {
        PNODE temp = Head;
        int iCnt = CountNode();

        if(iPos > iCnt+1 || iPos < 1)
            return;

        if(iPos == 1)
            InsertFirst(Head, Tail, data);
        else if(iPos == iCnt+1)
            InsertLast(Head, Tail, data);
        else
        {
            PNODE newn = new NODE(data);
            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;
            newn->next = temp->next;
            temp->next = newn;
        }  
    }

    int CountNode()
    {
        return NODE::iCnt;
    }

    void Display(PNODE Head)
    {
        if(Head == NULL)
            return;
        else
        {
            PNODE temp = Head;
            do
            {
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }while(temp!=Head);
        }
    }
};

class DoubllyCircular
{
    PNODE Head;
    PNODE Tail;
    public:

    DoubllyCircular()
    {
        Head = Tail = NULL;
    }

    void InsertFirst(int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
            Head = Tail = newn;
        else
        {
            newn->next = Head;
            newn->prev = Tail;
            Head->prev = newn;
            Tail->next = newn;
            Head = newn;
        }
    }

    void InsertLast(int data)
    {
        PNODE newn = new NODE(data);
        if(Head == NULL)
            Head = Tail = newn;
        else
        {
            Tail->next = newn;
            newn->prev = Tail;
            newn->next = Head;
            Head->prev = newn;
            Tail = newn;
        }
    }

    void InsertAtPos(int data, int iPos)
    {
        int iCnt = CountNode();
        if(iPos<1 || iPos>iCnt+1)
            return;
        else if(Head == NULL || iPos == 1)
            InsertFirst(data);
        else if(iPos == iCnt+1)
            InsertLast(data);
        else
        {
            PNODE newn = new NODE(data);
            PNODE temp = Head;

            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;
            
            newn->next = temp->next;
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
        }
    }

    void DeleteFirst()
    {
        if(Head == NULL)
            return;
        
        NODE :: iCnt--;
        Head = Head->next;
        delete []Head->prev;
        Head->prev = Tail;
        Tail->next = Head;
    }

    void DeleteLast()
    {
        if(Head == NULL)
            return;

        NODE::iCnt--;
        Tail = Tail->prev;
        delete []Tail->next;
        Head->prev = Tail;
        Tail->next = Head;
    }

    void DeleteAtPos(int iPos)
    {
        int iCnt = CountNode();
        if(Head == NULL || iPos<1 || iPos>iCnt)
            return;
        else if(iPos == iCnt)
            DeleteLast();
        else if(iPos == 1)
            DeleteFirst();
        else
        {
            PNODE temp = Head;
            for(int i = 1; i<iPos-1; i++)
                temp = temp->next;

            temp->next = temp->next->next;
            delete []temp->prev;
            temp->prev = temp;
        }
    }

    int CountNode()
    {
        return NODE::iCnt;
    }

    void Display()
    {
        PNODE temp = Head;
        if(temp == NULL)
            return;
        do
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp != Head);
    }
};

int main()
{
    /*
    Singly obj;
    PNODE Head = NULL;
    PNODE Tail = NULL;
    obj.InsertFirst(Head, Tail, 10);
    obj.InsertLast(Head, Tail, 8);
    obj.InsertFirst(Head, Tail, 20);
    obj.InsertLast(Head, Tail, 9);
    obj.InsertFirst(Head, Tail, 30);
    obj.InsertLast(Head, Tail, 7);

    obj.InsertAtPos(Head, Tail, 11, 3);
    obj.InsertAtPos(Head, Tail, 15, 2);
    // cout<<obj.CountNode()<<endl;
    // cout<<obj.CountNode()<<endl;

    obj.DeleteFirst(Head, Tail);
    obj.DeleteLast(Head, Tail);
    // obj.Display(Head);
    obj.DeleteAtPos(Head, Tail, 3);
    // obj.Display(Head);
    */

    /*
    PNODE Head = NULL, Tail = NULL;
    Dubbly obj2;
    obj2.InsertFirst(Head, Tail, 11);
    obj2.InsertFirst(Head, Tail, 21);
    obj2.InsertFirst(Head, Tail, 51);
    obj2.InsertLast(Head, Tail, 101);
    obj2.InsertLast(Head, Tail, 121);
    obj2.InsertAtPos(Head, Tail, 5, 6);

    obj2.Display(Head);
    cout<<endl;
    obj2.DeleteFirst(Head, Tail);
    obj2.DeleteLast(Head, Tail);
    obj2.DeleteAtPos(Head, Tail,3);
    obj2.Display(Head);
    */

    /*
    PNODE Head = NULL;
    PNODE Tail = NULL;
    SinglyCircular obj;
    obj.InsertFirst(Head, Tail, 11);
    obj.InsertLast(Head, Tail, 21);
    obj.InsertFirst(Head, Tail, 51);
    obj.InsertLast(Head, Tail, 101);
    obj.DeleteFirst(Head, Tail);
    obj.DeleteLast(Head, Tail);
    obj.InsertAtPos(Head, Tail, 45, 2);
    obj.DeleteAtPos(Head, Tail, 1);
    obj.Display(Head);
    */

    /*
    DoubllyCircular obj;
    obj.InsertFirst(51);
    obj.InsertLast(21);
    obj.InsertFirst(11);
    obj.InsertLast(102);
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.DeleteAtPos(1);
    obj.InsertAtPos(56,1);
    obj.Display();
    */
    
    return 0;
} 