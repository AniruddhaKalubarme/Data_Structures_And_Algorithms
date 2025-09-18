class pair
{
    int first;
    int second;
    pair(int a, int b)
    {
        first = a;
        second = b;
    }
}

class Solution
{
    //Function to return the maximum sum of non-adjacent nodes.
    static pair Solve(Node root)
    {
        if(root == null)
        {
            pair p = new pair(0,0);
            return p;
        }
            
        pair left = Solve(root.left);
        pair right = Solve(root.right);
        
        pair ans = new pair(0,0);
        ans.first = left.second + right.second + root.data;
        ans.second = Math.max(left.first, left.second) + Math.max(right.first, right.second);
        
        return ans;
    }
    
    static int getMaxSum(Node root)
    {
        pair ans = new pair(0,0);
        ans = Solve(root);
        return Math.max(ans.first, ans.second);
    }
}