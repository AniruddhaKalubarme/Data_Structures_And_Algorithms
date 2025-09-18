#include <iostream>
#include <vector>
#include "InsertFirst.cpp"
using namespace std;

// Approach 1
PNODE RevLL_Half(PNODE Head);

bool BreakLL(PNODE Head)
{
    int iCnt = Count(Head)/2;

    PNODE temp = Head;
    for(int i = 1; i < iCnt; i++)
        temp = temp->next;

    PNODE Head2 = temp->next;

    Head2 = RevLL_Half(Head2);

    temp->next = Head2;
    
    for(int i = 1; i <= iCnt; i++)
    {
        if(Head -> data != Head2 -> data)
            return false;

        Head2 = Head2->next;
        Head = Head->next;
    }

    return true;
}

PNODE RevLL_Half(PNODE Head)
{
    if(Head == NULL) return Head;
    
    
    PNODE prev = NULL;
    PNODE curr = Head;
    PNODE forw = curr -> next;
    while(curr != NULL)
    {
        curr -> next = prev;
        prev = curr;
        curr = forw;
        if(curr == NULL)
            break;
        forw = forw -> next;
    }
    return prev;
}

// Approach - 2
bool IsPalindrome(PNODE Head)
{
    if(Head == NULL) return true;

    vector <int> arr;

    while(Head != NULL)
    {
        arr.push_back(Head->data);
        Head = Head -> next;
    }

    int s = 0;
    int e = arr.size()-1;

    while(s<e)
    {
        if(arr[s] != arr[e]) return false;

        s++;
        e--;
    }

    return true;
}


int main()
{
    PNODE Head = NULL;
    // InsertFirst(Head, 15);
    InsertFirst(Head, 5);
    InsertFirst(Head, 10);
    InsertFirst(Head, 10);
    InsertFirst(Head, 15);
    InsertFirst(Head, 15);
    InsertFirst(Head, 10);
    InsertFirst(Head, 10);
    InsertFirst(Head, 5);

    Display(Head);
    cout<<endl;

    // Check only one condition at a time because the BreakLL changes the LL
    cout<<BreakLL(Head)<<endl;
    // cout<<IsPalindrome(Head)<<endl;
    return 0;
}