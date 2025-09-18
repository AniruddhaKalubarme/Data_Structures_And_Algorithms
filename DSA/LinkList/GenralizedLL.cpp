#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* down;

    node(int data) {
        this->data = data;
        next = down = NULL;
    }
};

typedef node* PNODE;

void InsertLastNext(PNODE& Head, PNODE& Tail, int data) {
    PNODE newn = new node(data);
    if (Head == NULL) {
        Head = Tail = newn;
    } else {
        Tail->next = newn;
        Tail = newn;
    }
}

void InsertLastDown(PNODE& Tail, int data) {
    if (Tail != NULL) {
        PNODE newn = new node(data);
        Tail->down = newn; // Link down
        Tail = newn; // Move Tail down
    }
}

void Display(PNODE Head) {
    while (Head != NULL) {
        cout << Head->data << " -> ";
        PNODE downTemp = Head->down; // Start with the down node
        while (downTemp != NULL) {
            cout << downTemp->data << " -> ";
            downTemp = downTemp->next; // Move through the down level
        }
        Head = Head->next; // Move to the next node at the same level
    }
    cout << "NULL" << endl; // End of the list
}

int main() {
    PNODE Head = NULL;
    PNODE TailNext = NULL;

    // Insert first level nodes
    InsertLastNext(Head, TailNext, 1);
    InsertLastNext(Head, TailNext, 5);
    InsertLastNext(Head, TailNext, 8);
    InsertLastNext(Head, TailNext, 10);

    // Insert down nodes for the first next node (1)
    PNODE TailDown1 = Head; // Point to the first node (1)
    InsertLastDown(TailDown1, 2);
    InsertLastDown(TailDown1, 3);
    InsertLastDown(TailDown1, 4);

    // Insert down nodes for the second next node (5)
    PNODE TailDown2 = Head->next; // Point to the second node (5)
    InsertLastDown(TailDown2, 6);
    InsertLastDown(TailDown2, 7);

    // Insert down node for the third next node (8)
    PNODE TailDown3 = Head->next->next; // Point to the third node (8)
    InsertLastDown(TailDown3, 9);

    // Display the list
    Display(Head);
    return 0;
}