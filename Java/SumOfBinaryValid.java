class Solution {
    
    int[] Sum(Node root)
    {
        if(root == null)
        {
            int arr[] = {1,0};
            return arr;
        }
        
        if(root.left == null && root.right == null)
        {
            int arr[] = {1,root.data};
            return arr;
        }
        
        
        
        int left[] = Sum(root.left);
        int right[] = Sum(root.right);
        
        int ans[] = new int[2];
        if(left[0] == 1 && right[0] == 1 && left[1] + right[1] == root.data)
            ans[0] = 1;
        else
            ans[0] = 0;
        
        ans[1] = left[1]+right[1]+root.data;
        
        return ans;
        
    }
    
    boolean isSumTree(Node root) {
        int ans[] = Sum(root);
        return ans[0] == 1 ? true : false;
    }
}