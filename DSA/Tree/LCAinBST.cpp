Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    if(root == NULL)
        return NULL;

    int data1 = P->data;
    int data2 = Q->data;
    if(root->data < data1 && root->data < data2)
        return LCAinaBST(root->right, P, Q);
    else if(root->data > data1 && root->data > data2)
       return LCAinaBST(root->left, P, Q);
    else
        return root;
}