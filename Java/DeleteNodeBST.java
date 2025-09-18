/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    TreeNode DeleteNode(TreeNode root, int key)
    {
        if(root == null)
            return null;
        
        if(root.val == key && root.left == null && root.right == null)
            return null;

        if(root.val == key && root.left != null && root.right == null)
            return root.left;
        
        if(root.val == key && root.left == null && root.right != null)
            return root.right;
        
        if(root.val == key && root.left != null && root.right != null)
        {
            TreeNode temp = root.left;
            while(temp.right != null)
                temp = temp.right;
            
            root.val = temp.val;

            root.left = DeleteNode(root.left, temp.val);
        }

        if(key<root.val)
            root.left = DeleteNode(root.left, key);
        else
            root.right = DeleteNode(root.right, key);
        return root;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        return DeleteNode(root, key);
    }
}