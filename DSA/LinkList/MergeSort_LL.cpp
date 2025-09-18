#include <iostream>
#include <limits.h> // For INT_MAX
#include "InsertFirst.cpp" // Ensure this file contains the definition for PNODE and NODE
using namespace std;

PNODE FindMid(PNODE Head) {
    PNODE fast = Head->next;
    PNODE slow = Head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

PNODE merge(PNODE left, PNODE right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    PNODE ans = new NODE(-1); // Create a dummy node
    PNODE temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left=left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

// Another Approach for merge
/*
PNODE merge(PNODE left, PNODE right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    PNODE ans = new NODE(-1); // Create a dummy node
    PNODE temp = ans;

    while(left != NULL || right != NULL)
    {
        int val1 = INT_MAX;
        int val2 = INT_MAX;

        if(left != NULL)
            val1 = left->data;

        if(right != NULL)
            val2 = right->data;

        if(val1 < val2)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    return ans->next;
}

*/

PNODE MergeSort(PNODE Head) {
    if (Head == NULL || Head->next == NULL) return Head; // Correct base case

    PNODE mid = FindMid(Head);

    PNODE left = Head;
    PNODE right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    PNODE result = merge(left, right);

    return result;
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

    Head = MergeSort(Head);
    Display(Head);
    return 0;
}