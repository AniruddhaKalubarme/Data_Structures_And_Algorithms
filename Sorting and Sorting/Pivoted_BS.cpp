#include <bits/stdc++.h>
using namespace std;

void BS(int *arr, int start, int end, int key)
{
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == key)
        {
            cout<<"The index is: "<<mid<<endl;
            return;
        }
        else if(arr[mid]>key)
            end = mid -1;
        else    
            start = mid+1;;
    }
    cout<<"Element not found"<<endl;
}

main()
{
    int k = 10;
    int arr[k] = {7,9,10,15,25,2,3,4,5,6};
    int l = 0, h= k-1, mid = (l+h)/2, key = 3;

    while(l<h)
    {
        if(arr[mid]<arr[0])
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
        
        mid = (l+h)/2;
    }
    
    

    if(key>arr[k-1])
    {
        // cout<<"Inside if block";
        BS(arr,0, l-1, key);
    }
    else
    {
        // cout<<"Inside else";
        BS(arr,l, k-1, key);
    }
    return 0;
}

