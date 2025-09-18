Node* FindMapping(Node* root, int data, map<Node*, Node*> &ChildToParent)
{
    if(root == NULL)
        return NULL;

    queue<Node*> q;
    q.push(root);
    ChildToParent[root] = NULL;
    Node* res = NULL;
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front->data == data)
            res = front;

        if(front->left)
        {
            ChildToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right)
        {
            ChildToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int BurnTree(Node* root, map<Node*, Node*> &ChildToParent)
{
    if(root == NULL)    return -1;

    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;
    int count = 0;
    
    while(!q.empty())
    {
        int tag = 0;
        int size = q.size();

        for(int i = 0; i<size; i++)
        {
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                tag = 1;
                visited[front->left] = true;
                q.push(front->left);
            }

            if(front->right && !visited[front->right])
            {
                tag = 1;
                visited[front->right] = true;
                q.push(front->right);
            }

            if(ChildToParent[front] && !visited[ChildToParent[front]])
            {
                tag = 1;
                visited[ChildToParent[front]] = true;
                q.push(ChildToParent[front]);
            }
        }

        if(tag)
            count++;
    }

    return count;
}

class Solution {
  public:
    int minTime(Node* root, int target) {
        map<Node*, Node*> ChildToParent;
        root = FindMapping(root, target, ChildToParent);

        return BurnTree(root, ChildToParent);
    }
};