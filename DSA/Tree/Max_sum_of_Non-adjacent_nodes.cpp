pair<int, int> Sum(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p = {0,0};
        return p;
    }
    
    pair<int, int> left = Sum(root->left);
    pair<int, int> right = Sum(root->right);
    
    pair<int, int> res;
    res.first = left.second + right.second + root->data;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}