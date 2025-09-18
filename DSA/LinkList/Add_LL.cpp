#include<iostream>
#include"InsertFirst.cpp"
using namespace std;

PNODE Reverse_LL(PNODE Head)
{
    PNODE prev = NULL;
    PNODE curr = Head;
    PNODE forw = curr -> next;

    while(forw != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = forw;
        forw = forw->next;
    }
    curr -> next = prev;
    return curr;
}


PNODE Add(PNODE Head1, PNODE Head2, PNODE Head)
{
    if(Head1 == NULL && Head2 == NULL)
        return NULL;
    else if(Head1 == NULL)
        return Head2;
    else if(Head2 == NULL)
        return Head1;

    Head1 = Reverse_LL(Head1);
    Head2 = Reverse_LL(Head2);

    int carry = 0;
    while(Head1 != NULL || Head2 != NULL || carry != 0)
    {
        int iVal1 = 0;
        if(Head1 != NULL)
        {
            iVal1 = Head1 -> data;
            Head1 = Head1->next;
        }

        int iVal2 = 0;
        if(Head2 != NULL)
        {
            iVal2 = Head2 -> data;
            Head2 = Head2->next; 
        }
        
        int iSum = iVal1 + iVal2 + carry;
        int digit = iSum%10;
        carry = iSum/10;

        InsertFirst(Head, digit);
        
         
    }
    return Head;
}

int main()
{
    PNODE Head1 = NULL;
    PNODE Head2 = NULL;
    PNODE Head = NULL;

    InsertFirst(Head1, 7);
    InsertFirst(Head1, 2);
    InsertFirst(Head1, 6);
    InsertFirst(Head1, 2);
    InsertFirst(Head1, 2);
    InsertFirst(Head2, 7);
    InsertFirst(Head2, 2);
    InsertFirst(Head2, 6);

    // Display(Head1);
    Head = Add(Head1, Head2, Head);
    Display(Head);

    return 0;
}