#include<iostream>
#include<vector>
using namespace std;

// Approach - 1 : using Top-Down
// TC & SC => O(N)
int f(int n, vector<int> &arr)
{
    if(n <= 1)
        return n;
    
    if(arr[n] != -1)
        return arr[n];

    arr[n] = f(n-1, arr)+f(n-2, arr);
    return arr[n];
}

// Approach - 2 : using Bottom-Up
// TC & SC => O(N)
int f2(int n){
    vector<int> arr(n+1, 0);
    arr[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        arr[i] = arr[i-2] + arr[i-1];
    }

    return arr[n];
}

// Optimise Space
// TC => O(N)
// SC => O(1)
int f3(int n){
    int first = 0;
    int sec = 1;

    
    for(int i = 2; i <= n; i++)
    {
        int curr = first + sec;
        first = sec;
        sec = curr;
    }

    return sec;
}

int main()
{

    int n = 6;
    vector<int> arr(n, -1);
    cout<<f(n-1, arr)<<endl;


    cout<<f2(n-1)<<endl;


    cout<<f3(n-1);
    return 0;
}