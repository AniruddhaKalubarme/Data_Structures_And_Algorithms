// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr)
    {
        int iMax = INT_MIN;
        
        if(arr.size()<3)
            return arr.size();
        
        for(int i = 0; i<arr.size()-1; i++)
        {
            for(int j = i+1; j<arr.size(); j++)
            {
                int iCnt = 0;
                int diff = arr[j]-arr[i];
                int curr = arr[j];
                for(int k = j-1; k>=0; k--)
                {
                    if(curr - arr[k] == diff)
                    {
                        iCnt++;
                        curr = arr[k];
                    }
                    else if(curr - arr[k] > diff)
                        break;
                }
                
                iMax = max(iMax, iCnt);
            }
        }
        
        return iMax+1;
    }
};