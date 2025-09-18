/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class info
{
    public:
    int iMin;
    int iMax;
    bool Tree;
    int iLength;
};

info Solve(TreeNode *root)
{
    if(root == NULL)
    {
        return {INT_MAX, INT_MIN, true, 0};
    }

    info left = Solve(root->left);
    info right = Solve(root->right);

    info obj;
    obj.iMin = min(left.iMin, root->data);
    obj.iMax = max(right.iMax, root->data);
    obj.iLength = left.iLength + right.iLength + 1;

    if(left.Tree && right.Tree && root->data < right.iMin && root->data > left.iMax)
    {
        obj.Tree = true;
        return obj;
    }
    else
    {
        return {INT_MAX, INT_MIN, false, max(left.iLength, right.iLength)};
    }
    
}
int largestBST(TreeNode * root){
    info obj;
    obj = Solve(root);
    return obj.iLength;
}