void Inorder(Node* root, vector<Node*> &ans)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->left, ans);
    ans.push_back(root);
    Inorder(root->right, ans);
}

void convert(vector<Node*> ans)
{
    for(int i = 0; i<ans.size()-1; i++)
    {
        ans[i]->left = NULL;
        ans[i]->right = ans[i+1];
    }

    // Last Node
    ans[ans.size()-1]->left = NULL;
    ans[ans.size()-1]->right = NULL;
}

int main()
{
    vector<Node*> ans;
    Inorder(root, ans);
    convert(ans);
    return ans[0];
}