class Solution {
    
    void solve(Node root, int lvl, ArrayList<Integer> arr)
    {
        if(root == null)
            return;
        
        if(arr.size() == lvl)
            arr.add(root.data);
        
        solve(root.left , lvl+1, arr);
        solve(root.right, lvl+1, arr);
    }
    
    ArrayList<Integer> leftView(Node root) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        solve(root, 0, arr);
        return arr;
    }
}