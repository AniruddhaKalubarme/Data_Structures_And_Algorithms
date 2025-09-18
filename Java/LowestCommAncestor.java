/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    TreeNode LCA(TreeNode root, TreeNode p, TreeNode q)
    {
        if(root == null) return null;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode left = LCA(root.left, p, q);
        TreeNode right = LCA(root.right, p, q);

        if(left == null && right == null)
            return null;
        else if(left != null && right == null)
            return left;
        else if(left == null && right != null)
            return right;
        else
            return root;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return LCA(root, p, q);
    }
}