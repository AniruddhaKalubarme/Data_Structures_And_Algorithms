#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left, *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    } 
};

Node* BuildTree(Node *root)
{
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    if(data == -1)
        return NULL;
    root = new Node(data);

    cout<<"Enter the left of "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the Right of "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void Display(Node *root)
{
    if(root == NULL)
        return;

    Display(root->left);
    cout<<root->data<<" -> ";
    Display(root->right);
}

// 1 3 4 -1 -1 9 -1 -1 7 -1 8 -1 -1