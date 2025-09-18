// NOT in the LOVE-BABBAR course

#include<iostream>
using namespace std;

typedef class node{
    public:
        int expo;
        int coeff;
        node *next;

    node(int coeff, int expo)
    {
        this->coeff = coeff;
        this->expo = expo;
        next = NULL;
    }

}NODE, * PNODE;

void InsertLast(PNODE &Head, PNODE &Tail, int coeff, int expo)
{
    PNODE newn = new NODE(coeff, expo);
    if(Head == NULL)
        Head = Tail = newn;
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
}

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        cout<<Head->coeff<< " : "<<Head->expo<<"  ->    ";
        Head = Head->next;
    }
    cout<<"NULL";
}

PNODE AddPoly(PNODE Head1, PNODE Head2)
{
    if(Head1 == NULL) return Head2;
    if(Head2 == NULL) return Head1;

    PNODE ans = NULL;
    PNODE ansTail = NULL;
    
    while(Head1 != NULL || Head2 != NULL)
    {
        int val1 = 0;
        if(Head1 != NULL)
            val1 = Head1->coeff;
                
        int val2 = 0;
        if(Head2 != NULL)
            val2 = Head2->coeff;

        if(Head1 -> expo == Head2 -> expo)
        {
            InsertLast(ans, ansTail, val1 + val2, Head1->expo);
            Head1 = Head1->next;
            Head2 = Head2->next;
        }
        else if(Head1 -> expo > Head2 -> expo)
        {
            InsertLast(ans, ansTail, val1, Head1->expo);
            Head1 = Head1->next;
        }
        else
        {
            InsertLast(ans, ansTail, val2, Head2->expo);
            Head2 = Head2->next;
        }
    }

    return ans;
}

int main()
{
    PNODE Head1 = NULL;
    PNODE Tail1 = NULL;
    PNODE Head2 = NULL;
    PNODE Tail2 = NULL;

    InsertLast(Head1, Tail1, 5,5);
    InsertLast(Head1, Tail1, 6,3);
    InsertLast(Head1, Tail1, 2,2);
    InsertLast(Head1, Tail1, 7,0);

    InsertLast(Head2, Tail2, 8,7);
    InsertLast(Head2, Tail2, 6,6);
    InsertLast(Head2, Tail2, 4,4);
    InsertLast(Head2, Tail2, 3,2);
    InsertLast(Head2, Tail2, 8,1); 
    InsertLast(Head2, Tail2, 9,0);

    Display(Head1);
    cout<<endl;
    Display(Head2);
    cout<<endl;
    PNODE ans = AddPoly(Head1, Head2);
    Display(ans);

    return 0;
}