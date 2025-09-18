#include <iostream>
#include "InsertFirst.cpp"
using namespace std;

void Sort(PNODE Head)
{
    int iCnt0 = 0, iCnt1 = 0, iCnt2 = 0;
    PNODE temp = Head;
    while(temp != NULL)
    {
        if(temp->data == 0)
            iCnt0++;
        else if(temp->data == 1)
            iCnt1++;
        else if(temp->data == 2)
            iCnt2++;
        
        temp = temp->next;
    }

    while(Head != NULL)
    {
        if(iCnt0-- > 0)
            Head->data = 0;
        else if(iCnt1-- > 0)
            Head->data = 1;
        else if(iCnt2-- > 0)
            Head->data = 2;

        // cout<<iCnt0<<iCnt1<<iCnt2<<endl;
        Head = Head->next;
    }
}

// Approach-2
void InsertFirst(PNODE &Head, PNODE &Tail, PNODE newn)
{
    if(Head == NULL)
    {
        Head = newn;
        Tail = newn;
        Tail->next = NULL;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
}

PNODE Sort_012(PNODE Head)
{
    if(Head == NULL)
        return NULL;

    // PNODE temp = Head;
    PNODE zero = NULL, one = NULL, two = NULL;
    PNODE Tail_zero = NULL, Tail_one = NULL, Tail_two = NULL;

    while(Head != NULL)
    {
        // Below  two lines are COMPULSURY
        // We need to de-link the nodes from original LL
        PNODE temp = Head;
        Head = Head->next;

        if(temp->data == 0)
            InsertFirst(zero, Tail_zero, temp);
        else if(temp->data == 1)
            InsertFirst(one, Tail_one, temp);
        else if(temp->data == 2)
            InsertFirst(two, Tail_two, temp);

        temp = temp->next;
    }
    
    Tail_zero->next = one;
    Tail_one->next = two;

    return zero;
}

// Approach -3 
void InsertLast(PNODE &Head, PNODE &Tail, PNODE newn)
{
    // It contains one NODE already therfore no need to check base condition
    Tail->next = newn;
    Tail = newn;
}

void Sort_012_2(PNODE &Head)
{
    if(Head == NULL) return;

    PNODE Zero = new NODE(-1);
    PNODE One = new NODE(-1);
    PNODE Two = new NODE(-1);

    PNODE Zero_Tail = Zero;
    PNODE One_Tail = One;
    PNODE Two_Tail = Two;
    
    while(Head != NULL)
    {
        if(Head -> data == 0)
            InsertLast(Zero, Zero_Tail, Head);
        else if(Head -> data == 1)
            InsertLast(One, One_Tail, Head);
        else if(Head -> data == 2)
            InsertLast(Two, Two_Tail, Head);

        Head = Head -> next;
    }

    if(One -> next != NULL)
        Zero_Tail -> next = One -> next;
    else
        Zero_Tail -> next = Two -> next;

    One_Tail -> next = Two -> next;
    Two_Tail -> next = NULL;

    Head = Zero->next;

    delete Zero;
    delete One;
    delete Two;
}

int main()
{
    PNODE Head = NULL;
    InsertFirst(Head, 1);
    InsertFirst(Head, 0);
    InsertFirst(Head, 2);
    InsertFirst(Head, 1);
    InsertFirst(Head, 0);
    InsertFirst(Head, 0);

    // Sort(Head);
    Sort_012_2(Head);
    Display(Head);
    return 0;
}