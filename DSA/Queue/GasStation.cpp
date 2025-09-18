#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int balance = 0;
        int required = 0;
        int start = 0;
        
        for(int i = 0; i<gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if(balance < 0)
            {
                required += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(required+balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};
