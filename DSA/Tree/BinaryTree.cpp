#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class NODE
{
    public:
    int data;
    NODE *left, *right;

    NODE(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

NODE* BuildTree(NODE* root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;

    if(data == -1)
        return NULL;
    root = new NODE(data);

    cout<<"Enter the data for left of : "<<data<<endl;;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for right of :"<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void Display(NODE *root)
{
    queue<NODE *> q;
    q.push(root);

    while(!q.empty())
    {
        NODE *temp = q.front();
        cout<<temp->data<<" -> ";
        q.pop();

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

void DisplayLevelWise(NODE *root)
{
    queue<NODE*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        NODE *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty()) q.push(NULL); // Remaining elements
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

void DisplayRevLvl(NODE *root)
{
    queue<NODE*> q;
    stack<NODE*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        NODE *temp = q.front();
        s.push(temp);
        q.pop();

        if(temp == NULL)
        {
            if(!q.empty()) q.push(NULL); // Remaining elements
        }
        else
        {
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }

    while(!s.empty())
    {
        if(s.top() != NULL)
        {
            cout<<(s.top())->data<<" ";
        }
        else
        {
            cout<<endl;
        }
        s.pop();
    }
}

int main()
{
    NODE * root;
    root = BuildTree(root);
    cout<<"\nData is: "<<endl;
    DisplayLevelWise(root);
    cout<<"\n\nReversed Data is: "<<endl;
    DisplayRevLvl(root);
    return 0;
}

// Data:- 1 3 4 -1 -1 9 -1 -1 7 -1 8 -1 -1