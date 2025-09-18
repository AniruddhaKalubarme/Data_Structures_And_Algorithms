class Solution {
    int countWays(int n, int k) {
        if(n==1)
            return k;
        
        if(n==2)
            return (k+k*(k-1));
            
        return (countWays(n-1, k) * (k-1)) + (countWays(n-2, k) * (k-1));
    }
}

