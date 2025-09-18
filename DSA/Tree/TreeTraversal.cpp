#include<iostream>
#include<stack>
using namespace std;

class NODE
{
    public:
    int data;
    NODE *right;
    NODE *left;

    NODE(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

NODE* BuildTree(NODE *root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;

    if(data == -1)
        return NULL;
    root = new NODE(data);

    cout<<"Enter the left of "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the right of "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void Inorder(NODE *root)
{
    if(root == NULL)
        return;

    Inorder(root->left);
    cout<<root->data<<" -> ";
    Inorder(root->right);
}

void Preorder(NODE *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" -> ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(NODE *root)
{
    if(root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" -> ";
}

void Inorder_Iteration(NODE *root) {
    stack<NODE*> s;
    while (true) {
        // Traverse the left subtree
        while (root) {
            s.push(root);
            root = root->left;
        }
        
        // If the stack is empty, we are done11
        if (s.empty()) break;

        // Process the top node in the stack
        root = s.top();
        s.pop();
        cout << root->data << " -> ";

        // Traverse the right subtree
        root = root->right;
    }
}


int main()
{
    NODE *root;
    root = BuildTree(root);
    cout<<endl<<endl;
    Inorder(root);
    // cout<<endl;
    // Preorder(root);
    cout<<endl;
    // Postorder(root);
    Inorder_Iteration(root);
    return 0;
}