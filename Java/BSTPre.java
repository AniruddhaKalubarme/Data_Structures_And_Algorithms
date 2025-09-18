static class Solution {
    // Function that constructs BST from its preorder traversal.
    
    Node Construct(int pre[], int index[], int min, int max)
    {
        if(index[0]>=pre.length)
            return null;
        
        if(pre[index[0]] < min || pre[index[0]] > max)
            return null;
        
        int ele = pre[index[0]++];
        Node newn = new Node(ele);
        
        newn.left = Construct(pre, index, min, ele);
        newn.right = Construct(pre, index, ele, max);
        
        return newn;
    }
    
    public Node Bst(int pre[], int size) {
            
        int arr[] = {0};
        return Construct(pre, arr, Integer.MIN_VALUE, Integer.MAX_VALUE);
        
    }
}
