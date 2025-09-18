#include<iostream>
#include<vector>
#include<queue>
#include"BuildTree.cpp"
using namespace std;

vector<int> SpiralTraverse(NODE *root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }

    queue<NODE*> q;
    q.push(root);
    bool leftToright = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for(int i = 0; i<size; i++)
        {
            NODE* front = q.front();
            q.pop();

            int index = leftToright ? i:size-i-1;
            ans[index] = front->data;

            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        leftToright = !leftToright;
        for(auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;

}

int main()
{
    NODE* root = BuildTree(root);
    vector<int> ans = SpiralTraverse(root);
    for(auto i : ans)
        cout<<i<<" ";
    return 0;
}