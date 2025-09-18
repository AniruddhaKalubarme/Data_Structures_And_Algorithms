void Inorder(BinaryTreeNode* root, vector<int> &ans)
{
	if(root == NULL)
		return;
	
	Inorder(root->left,ans);
	ans.push_back(root->data);
	Inorder(root->right, ans);
}

void FillTree(BinaryTreeNode* root, vector<int> ans, int &index)
{
	if(!root)
		return;
	
	root->data = ans[index++];
	FillTree(root->left, ans, index);
	FillTree(root->right, ans, index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	Inorder(root, ans);
	int index = 0;
	FillTree(root, ans, index);
	return root;
}