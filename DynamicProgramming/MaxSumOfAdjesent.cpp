#include <bits/stdc++.h> 

int solve(vector<int> &nums, int i)
{
    if(nums.size()<=i)
        return 0;

    int include = nums[i] + solve(nums, i+2);
    int exclude = solve(nums, i+1);

    return max(include, exclude);
}

int solveTopDown(vector<int> &nums, int i, vector<int> &dp)
{
    if(nums.size() <= i)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int include = nums[i] + solveTopDown(nums, i+2, dp);
    int exclude = solveTopDown(nums, i+1, dp);

    dp[i] = max(include, exclude);
    return dp[i];
}

int solveBottomUp(vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];

    for(int i = 1; i<nums.size(); i++)
    {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]+0);
    }

    return dp[dp.size()-1];
}

int solveSpaceOptimised(vector<int> &nums)
{

    int first = nums[0];
    int second = 0;

    for(int i = 1; i<nums.size(); i++)
    {
        int temp = max(second+nums[i], first+0);
        second = first;
        first = temp;
    }

    return first;
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return solveSpaceOptimised(nums);
} 