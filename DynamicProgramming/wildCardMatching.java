class Solution {

    int solve(String s, String p, int i, int j, int [][]dp)
    {
        // both strings ended
        if(i == -1 && j == -1)  return 1;

        // only pattern ended
        if(i > -1 && j == -1)   return 0;

        // only string(s) ended
        if(i == -1 && j > -1)
        {
            for(int k = 0; k<=j; k++)
                {
                    if(p.charAt(k) != '*')
                        return 0;
                }

                return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(p.charAt(j) == '?' || s.charAt(i) == p.charAt(j))
        {
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        }
        else if(p.charAt(j) == '*')
        {
            //Empty string || *[char] oparation
            return dp[i][j] = (solve(s, p, i, j-1, dp) | solve(s, p, i-1, j, dp));
        }
        else
        {
            return dp[i][j] = 0;
        }
    }

    public boolean isMatch(String s, String p) {
        int [][]dp = new int[s.length()+1][p.length()+1];
        for(int []row : dp)
            Arrays.fill(row, -1);
        
        return solve(s, p, s.length()-1, p.length()-1, dp) == 1 ? true : false;
    }
}