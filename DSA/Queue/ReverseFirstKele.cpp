
void rev(queue<int> &q, int k, int size)
{
    if(k==0)
    {
        return;
    }
    
    int num = q.front();
    q.pop();
    
    rev(q,--k, size);
    
            // cout<<k <<" -> "<<size<<endl;
    q.push(num);
    
    if(k == size-1)
    {
        for(int i = 0; i<q.size()-k-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
}

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        rev(q, k, k);
        return q;
    }
};
