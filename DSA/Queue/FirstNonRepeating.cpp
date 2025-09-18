#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &str) {
        map<char, int> freq;
        queue<char> q;
        string ans = "";
        for(int i = 0; i<str.length(); i++)
        {
            freq[str[i]]++;
            q.push(str[i]);
            
            while(!q.empty())
            {
                if(freq[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty())
            {
                ans.push_back('#');
            }
        }
        
        return ans;
        
    }
};
