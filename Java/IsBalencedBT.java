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
    int[] Balanced(TreeNode root)
    {
        if(root == null)
        {
            int p[] = {1,0};
            return p;
        }

        int left[] = Balanced(root.left);
        int right[] = Balanced(root.right);

        int ans[] = new int[2];
        ans[1] = Math.max(left[1] , right[1])+1;

        if(left[0] == 1 && right[0] == 1 && Math.abs(left[1] - right[1]) <= 1)
            ans[0] = 1;
        else
            ans[0] = 0;

        return ans;
    }

    public boolean isBalanced(TreeNode root) {
        int []arr;
        arr = Balanced(root);
        if(arr[0] == 1)
            return true;
        else
            return false;
    }
}