class greaterN{
    public:
    bool operator()(Node* o1, Node* o2)
    {
        return o1->data > o2->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* Head = NULL;   
        Node* Tail = NULL;
        if(arr.size() == 0)
            return Head;
        
        priority_queue<Node*, vector<Node*>, greaterN> pq;
    
        int k = arr.size();
        for(int i = 0; i<k;i++)
        {
            pq.push(arr[i]);
        }
    
        while(pq.size()>0)
        {
            Node* top = pq.top();
            pq.pop();
            
            if(top->next != NULL)
                pq.push(top->next);
                
            if(Head == NULL)
                Head=Tail=top;
            else
            {
                Tail->next = top;
                Tail = top;
            }
        }
        
        return Head;
    }
};