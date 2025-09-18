#include <iostream>
#include "InsertFirst.cpp"
using namespace std;

void Make_It_Circular(PNODE Head)
{
    if(Head == NULL)
        return;

    PNODE temp = Head;
    
    do
    {
        temp = temp->next;
    }while(temp->next != NULL && temp->next != Head);
    temp -> next = Head;
}

// Approach - 1
PNODE Devide_LL_In_2_Parts(PNODE Head)
{
    if(Head == NULL)
        return NULL;

    int iCnt = NODE::iCnt;

    PNODE temp = Head->next;
    PNODE prev = Head;
    PNODE Head2 = NULL;
    for(int i = 1; temp->next != Head; i++)
    {
        if(i == iCnt/2)
            Head2 = temp;

        if(i == iCnt/2-1)
            prev = temp;

        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = NULL;
    return Head2;
}

// Approach - 2
PNODE Devide_LL_In_2_Parts_2_Approach(PNODE Head)
{
    if(Head == NULL)
        return NULL;

    PNODE Head2 = NULL;
    PNODE slow = Head;
    PNODE fast = Head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast->next != Head && fast != Head);

    Head2 = slow->next;
    slow->next = Head;
    fast->next = Head2;
    return Head2;
}


void Display_CLL(PNODE Head)
{
    if(Head == NULL)
        return;
    
    PNODE temp = Head;
    do
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }while(temp != Head);
    cout<<"CONTINUE";
}

int main()
{
    PNODE Head = NULL;
    InsertFirst(Head, 30);
    InsertFirst(Head, 20);
    InsertFirst(Head, 10);
    InsertFirst(Head, 5);
    InsertFirst(Head, 2);

    Make_It_Circular(Head);

    PNODE Head2 = Devide_LL_In_2_Parts_2_Approach(Head);

/*

    Make_It_Circular(Head);
    Make_It_Circular(Head2);

*/
    Display_CLL(Head);
    cout<<endl;
    Display_CLL(Head2);


    return 0;
}