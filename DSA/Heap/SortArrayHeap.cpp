#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int arr[100];
    int MainIndex = 0;
    void Build(int data)
    {
        MainIndex++;
        int index = MainIndex;
        arr[index] = data;
        
        while(index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index = index/2;
            }
            else
                break;
        }
    }
    
    void HeapiFy(int i)
    {
            int iMax = i;
            int left = iMax*2;
            int right = left+1;
            
            if(left<=MainIndex && arr[left]>arr[iMax])
                iMax = left;
            if(right <= MainIndex && arr[right]>arr[iMax])
                iMax = right;
            
            if(iMax != i)
            {
                swap(arr[iMax], arr[i]);
                HeapiFy(iMax);
            }
    }
    
    void Sort()
    {
        int i = 1;
        while(MainIndex>1)
        {
            swap(arr[1], arr[MainIndex]);
            MainIndex--;
        
            HeapiFy(1);
        }
    }
    
    void heapSort(vector<int>& vec) {
        int n = vec.size();
        
        for(int i = 0; i<n; i++)
        {
            Build(vec[i]);
        }
        
        Sort();
        
        for(int i = 0; i<n; i++)
        {
            vec[i] = arr[i+1];
        }

    }
};


int main() {
    vector<int> arr{4,1,3,9,7};
    Solution obj;
    // obj.heapSort(arr);
    
    for(int i = 0; i<5; i++)
        obj.Build(arr[i]);

    for(int i = 1; i<6; i++)
    {
        cout<<obj.arr[i]<<" -> ";
    }
    
    return 0;
}

// } Driver Code Ends