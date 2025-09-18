#include<iostream>
#include<queue>
#include"BuildTree.cpp"
using namespace std;

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

bool FindNode(Node* root, int x)
{
    if(root == NULL)
        return false;

    if(root->data == x)
        return true;

    if(x>root->data)
    return FindNode(root->right, x);
    else
    return FindNode(root->left, x);
}

void LevelOrd(Node* root)
{
    queue<Node*> q;
    if(root == NULL)
        return;

    q.push(root);
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        cout<<front->data<<" -> ";

        if(front->left)
        {
            q.push(front->left);
        }

        if(front->right)
        {
            q.push(front->right);
        }
    }
}

Node* FindMin(Node* root)
{
    if(root == NULL)
        return NULL;

    while(root->left)
        root = root->left;

    return root;
}

Node* DeleteNode(Node* root, int x)
{
    if(root == NULL)
        return NULL;

    if(root->data == x)
    {
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if(!root->left && root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left && !root->right)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // cout<<"HERE";
            Node* iMin = FindMin(root->right);
            root->data = iMin->data;
            root->right = DeleteNode(root->right, iMin->data);
            return root;
        }
    }

    root->left = DeleteNode(root->left, x);
    root->right = DeleteNode(root->right, x);

    return root;
}

int main()
{
    Node* root = NULL;
    Insert(root);
    LevelOrd(root);
    cout<<endl;
    DeleteNode(root, 5);
    LevelOrd(root);
    return 0;
}

// 10 5 15 3 8 20 -1