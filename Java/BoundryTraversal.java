class Solution {
    
    void leftT(Node root, ArrayList<Integer> ans) {
        if (root == null || (root.left == null && root.right == null)) return;
        
        ans.add(root.data); 
        
        if (root.left != null) leftT(root.left, ans); 
        else leftT(root.right, ans); 
    }

    void leafT(Node root, ArrayList<Integer> ans) {
        if (root == null) return;
        
        leafT(root.left, ans);
        if (root.left == null && root.right == null) ans.add(root.data);
        leafT(root.right, ans);
    }

    
    void rightT(Node root, ArrayList<Integer> ans) {
        if (root == null || (root.left == null && root.right == null)) return;

        if (root.right != null) rightT(root.right, ans);
        else rightT(root.left, ans); 
        
        ans.add(root.data); 
    }
    
    ArrayList<Integer> boundaryTraversal(Node node) {
        ArrayList<Integer> ans = new ArrayList<>();

        if (node == null) return ans;
        
        // Only one Node (leaf + root)
        if (node.left == null && node.right == null)
        {
            ans.add(node.data);
            return ans;
        }
        
        ans.add(node.data);
        leftT(node.left, ans);
        leafT(node, ans);
        rightT(node.right, ans);


        return ans;
    }
}
