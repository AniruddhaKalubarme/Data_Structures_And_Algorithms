#include<iostream>
#include"InsertFirst.cpp"
using namespace std;

PNODE MergeSort(PNODE Head1, PNODE Head2)
{
    if(Head1 == NULL) return Head2;
    if(Head2 == NULL) return Head1;

    if(Head1->data > Head2->data)
    {
        swap(Head1, Head2);
    }
    
    // PNODE MainHead = Head1;
    PNODE prev = Head1;
    PNODE curr = Head1->next;
    PNODE temp = Head2;

    while(curr != NULL && temp != NULL)
    {
        if(prev->data <= temp->data && curr->data >= temp->data)
        {
            Head2 = Head2 -> next;
            prev->next = temp;
            temp->next = curr;
            prev = temp;
            temp = Head2;
        }
        else
        {
            prev = curr;
            curr = curr -> next;

            if(prev->next == NULL)
            {
                prev->next = temp;
                return Head1;
            }
        }
    }

    if(Head1->next == NULL)
        Head1->next = Head2;

    return Head1;
}

int main()
{
    PNODE Head1 = NULL;
    PNODE Head2 = NULL;
    
    InsertFirst(Head1, 6);
    InsertFirst(Head1, 5);
    InsertFirst(Head1, 3);
    InsertFirst(Head1, 1);

    InsertFirst(Head2, 5);
    InsertFirst(Head2, 4);
    InsertFirst(Head2, 2);
    InsertFirst(Head2, 0);

    PNODE Head = MergeSort(Head1, Head2);
    Display(Head);
    return 0;
}