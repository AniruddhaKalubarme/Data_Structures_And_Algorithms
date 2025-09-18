#include <iostream>
#include "InsertFirst.cpp"
using namespace std;

PNODE Sort_DATA(PNODE Head)
{
    PNODE Head1 = Head, Head2 = Head;
    while(Head1!=NULL)
    {
        Head2 = Head1;
        while(Head2!=NULL)
        {
            if(Head1->data > Head2->data)
            {
                swap(Head1->data, Head2->data);
            }
            Head2 = Head2->next;
        }
        Head1 = Head1->next;
    }

    return Head;
}

PNODE Sort_NODES(PNODE Head)
{
    PNODE Head1 = Head, Head2 = Head;
    PNODE ans = new NODE(-1);

    PNODE temp = NULL, temp2 = ans;
    while(Head1!=NULL)
    {
        Head2 = temp = Head1;
        while(Head2!=NULL)
        {
            if(temp -> data > Head2->data)
            {
               temp = Head2; 
            }
            Head2 = Head2->next;
        }
            // cout<<"Glitch";
        temp2->next = temp;
        temp2 = temp;

        if(Head1 == temp)
            Head1 = Head1->next;
        else
        {
            PNODE traveller = Head1;
            while(traveller->next != temp)
            {
                traveller = traveller -> next;
            }

            traveller->next = traveller -> next -> next;
        }
    }

    return ans->next;
}

int main() {
    PNODE Head = NULL;
    InsertFirst(Head, 36);
    InsertFirst(Head, 5);
    InsertFirst(Head, 18);
    InsertFirst(Head, 65);
    InsertFirst(Head, 23);
    InsertFirst(Head, 1);
    InsertFirst(Head, 15);
    InsertFirst(Head, 1);

    Head = Sort_NODES(Head);
    PNODE Head2 = Sort_DATA(Head);
    Display(Head);
    cout<<endl;
    Display(Head2);
    return 0;
}