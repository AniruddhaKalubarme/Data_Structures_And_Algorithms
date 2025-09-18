void HeapiFy(vector<int> &arr, int ele, int index)
{
    int left = index*2+1;
    int right = index*2+2;
    int iMax = index;
    
    if(left<arr.size() && arr[iMax] < arr[left])
        iMax = left;
    if(right<arr.size() && arr[iMax] < arr[right])
        iMax = right;
    
    if(iMax != index)
    {
        swap(arr[iMax], arr[index]);
        HeapiFy(arr, ele, iMax);
    }
    else
    {
        return;
    }
}

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans = a;
        
        for(auto i:b)
            ans.push_back(i);
        
        int size = ans.size();
        for(int i = size/2 -1; i>=0; i--)
        {
            HeapiFy(ans, ans[i], i);
        }
        
        return ans;
    }
};