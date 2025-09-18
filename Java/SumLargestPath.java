class pair
{
    int sum;
    int height;
    pair(int s, int h)
    {
        sum = s;
        height = h;
    }
}

class Solution{
    
    pair solve(Node root)
    {
        if(root == null)
        {
            pair p = new pair(0,0);
            return p;
        }
        
        pair left = solve(root.left);
        pair right = solve(root.right);
        
        pair ans = new pair(root.data , 1);
        
        
        if(left.height > right.height)
        {
            ans.height = left.height+1;
            ans.sum = left.sum+root.data;
        }
        else if(left.height < right.height)
        {
            ans.height = right.height+1;
            ans.sum = right.sum+root.data;
        }
        else 
        {
            ans.height = left.height+1;
            ans.sum = Math.max(left.sum, right.sum) + root.data;
        }
        
        return ans;
    }
    
    public int sumOfLongRootToLeafPath(Node root)
    {
        pair obj = solve(root);
        return obj.sum;
    }
}