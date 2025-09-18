#include<iostream>
using namespace std;

void Inorder(Node* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}

Node* Construct(vector<int> &ans, int s, int e)
{
    if(s>e)
        return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(ans[mid]);

    root->left = Construct(ans, s, mid-1);
    root->right = Construct(ans, mid+1, e);

    return root;
}

Node* balancedBst(Node* root) {
    vector<int> ans;
    Inorder(root, ans);
    return Construct(ans, 0, ans.size()-1);
}