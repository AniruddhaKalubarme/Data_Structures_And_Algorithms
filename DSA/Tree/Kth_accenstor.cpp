// Aproach - 1
void Find(Node* root, int val, int k, vector<int> ans, int &op)
{
    if(root == NULL)
        return;
        
    ans.push_back(root->data);
    if(root->data == val)
    {
        for(int i = 0; i<k; i++)
        {
            ans.pop_back();
            if(ans.size() == 0)
            {
                op = -1;
                return;
            }    
        }

        op = ans[ans.size()-1];  
    }
    
    
    Find(root->left, val, k, ans, op);
    Find(root->right, val, k, ans, op);
}

int kthAncestor(Node *root, int k, int node)
{
    int ans1 = 0;
    vector<int> ans;
    Find(root, node, k, ans, ans1);
    return ans1;
    
}

// Aproach - 2
Node* Find(Node* root, int val, int &k)
{
    if(root == NULL)
        return NULL;

    if(root -> data == val)
    {
        return root;
    }

    Node* left = Find(root->left, val, k);
    Node* right = Find(root->right, val, k);

    if(left == NULL && right != NULL )
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }

    if(left != NULL && right == NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }

    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans;
    ans = Find(root, node, k);
    if(root->data == node || ans->data == node)
        return -1;
    return ans->data;
    
}