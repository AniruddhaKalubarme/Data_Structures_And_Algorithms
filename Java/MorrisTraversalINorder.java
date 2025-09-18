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
    List<Integer> Inorder(TreeNode root)
    {
        List<Integer> arr = new ArrayList<>();
        if(root == null)
            return arr;
        
        TreeNode curr = root;
        while(curr!=null)
        {
            if(curr.left == null)
            {
                arr.add(curr.val);
                curr = curr.right;
            }
            else
            {
                TreeNode prev = curr.left;
                while(prev.right!=null && prev.right!=curr)
                {
                    prev = prev.right;
                }

                if(prev.right == null)
                {
                    prev.right = curr;
                    curr = curr.left;
                }
                else
                {
                    arr.add(curr.val);
                    prev.right = null;
                    curr = curr.right;
                }
            }
        }

        return arr;
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        return Inorder(root);
    }
}