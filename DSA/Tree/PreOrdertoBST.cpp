Node* Construct(vector<int> arr, int &index, int iMin, int iMax)
{
    if(index>=arr.size())
        return NULL;

    if(arr[index]<iMin || arr[index]>iMax)
        return NULL;

    Node* root = new Node(arr[index++]);
    root->left = Construct(arr, index, iMin, root->data);
    root->right = Construct(arr, index, root->data, iMax);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int iMin = INT_MIN;
    int iMax = INT_MAX;
    int index = 0;
    return Construct(preorder, index, iMin, iMax);
}