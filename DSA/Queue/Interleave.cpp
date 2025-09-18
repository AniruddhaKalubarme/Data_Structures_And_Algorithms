#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q2){
        queue<int> q1;
        int size = (q2.size()+1)/2;
        
        for(int i = 0; i<size; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        
        vector<int> ans;
        
        for(int i = 0; i<size; i++)
        {
            ans.push_back(q1.front());
            q1.pop();
            
            ans.push_back(q2.front());
            q2.pop();
        }
        
        return ans;
    }
};
