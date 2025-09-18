
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& A, int k) {
        deque<long long int> dq;
        vector<int> ans;
        int N = A.size();
        
        for(int i = 0; i<k; i++)
        {
            if(A[i]<0)
                dq.push_back(i);
        }
        
        if(dq.size() > 0)
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
            
        for(int i = k; i<N; i++)
        {
            if(!dq.empty() && i-dq.front() >= k)
                dq.pop_front();
                
            if(A[i] < 0)
                dq.push_back(i);
            
            if(dq.size() > 0)
                ans.push_back(A[dq.front()]);
            else
                ans.push_back(0);
        }
        
        return ans;
    }
};

