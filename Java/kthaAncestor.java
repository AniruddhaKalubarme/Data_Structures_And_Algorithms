class Solution {
    
    int Find(Node root, int arr[], int node)
    {
        if(root == null)
            return -1; 
        
        if(root.data == node)
            return root.data;
            
        int left = Find(root.left, arr, node);
        int right = Find(root.right, arr, node);
        
        if(left == -1 && right != -1)
        {
            
            arr[0]--;
            if(arr[0]==0){
                return root.data;
            }
            else
                return right;
        }
        
        if(left != -1 && right == -1)
        {
            arr[0]--;
            if(arr[0]==0){
                 return root.data;
            }
            else
                return left;
        }
        
        return -1;
        
    }
    
    public int kthAncestor(Node root, int k, int node) {
        int arr[] = {k};
        int val = Find(root, arr, node);
        if( val == node )
            return -1;
        else
            return val;
    }
}