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

    int Find(TreeNode root, int k[])
    {
        if(root == null)
            return -1;
        
        int left = Find(root.left, k);
        k[0]--;
        if(k[0] == 0)
        {
            return root.val;
        }
        int right = Find(root.right, k);       
        
        if(left == -1 && right == -1) return -1;
        else if(left != -1) return left;
        else return right;
    }

    public int kthSmallest(TreeNode root, int k) {
        int arr[] = {k};
        return Find(root, arr);
    }
}