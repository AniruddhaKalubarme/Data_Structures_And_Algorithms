// Problem is same as MaxSumOfAdjecent...

#include <bits/stdc++.h> 

long long int solve(vector<int>& arr, int i, int n)
{
    if(i>=n)
        return 0;
    
    return max(solve(arr, i+2, n) + arr[i] , solve(arr, i+1, n)+0);
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];

    return max(solve(valueInHouse, 0, n-1), solve(valueInHouse, 1, n));
}


// Approach - 2 DP
#include <bits/stdc++.h> 

long long int solve(vector<int>& arr, int i, int n, vector<long long int> &dp)
{
    if(i>=n)
        return 0;

    if(dp[i] != -1)
        return dp[i];
    
    dp[i] = max(solve(arr, i+2, n, dp) + arr[i] , solve(arr, i+1, n, dp)+0);
    return dp[i];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];

    vector<long long int> dp1(n, -1), dp2(n, -1);
        
    return max(solve(valueInHouse, 0, n-1, dp1), solve(valueInHouse, 1, n, dp2));
}