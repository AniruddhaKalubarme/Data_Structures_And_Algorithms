#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Node
{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* AddData(Node* root, int x)
{
    if(root == NULL)
    {
       return new Node(x);
    }

    if(root->data < x)
    {
        root->right = AddData(root->right, x);
    }
    else
    {
       root->left = AddData(root->left, x);
    }

    return root;
}

void Insert(Node* &root)
{
    while(1)
    {
        int data;
        cin>>data;
        if(data == -1)
            break;
        
        root = AddData(root, data);
    }
}

void Decresing(Node* root, vector<int> &ans)
{
    stack<Node*> s;

    Node* temp = root;
    while(!s.empty() || temp)
    {
        while(temp)
        {
            s.push(temp);
            temp = temp->right;
        }

        temp = s.top();
        ans.push_back(temp->data);
        s.pop();
        temp = temp->left;
    }
}

int main()
{
    Node* root = NULL;
    Insert(root);
    vector<int> ans;
    Decresing(root, ans);
    for(auto i:ans)
        cout<<i<<" -> ";
    return 0;
}