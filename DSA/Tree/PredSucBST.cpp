void Solve(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp = root;
    if(temp == NULL)
        return;
        
    while(temp && temp->key != key)
    {
        if(temp->key > key)
        {
            suc = temp;
            temp = temp->left;
        }
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }
    
    if(temp == NULL)
        return;
    
    Node* leftTree = temp->left;
    while(leftTree != NULL)
    {
        pre = leftTree;
        leftTree = leftTree->right;
    }
    
    
    Node* rightTree = temp->right;
    while(rightTree != NULL)
    {
        suc = rightTree;
        rightTree = rightTree->left;
    }
}