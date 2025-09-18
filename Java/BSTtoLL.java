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
    void Inorder(TreeNode root, ArrayList<TreeNode> ans)
    {
        if(root == null)
            return;
            
        ans.add(root);
        Inorder(root.left, ans);
        Inorder(root.right, ans);
    }

    public void flatten(TreeNode root) {
        ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
        Inorder(root, ans);
        ans.add(null);

        for(int i = 0; i<ans.size()-1; i++)
        {
            ans.get(i).right = ans.get(i+1);
            ans.get(i).left = null;
        }
    }
}


//Approach-2
class Solution {
  private TreeNode head;
  public void flatten(TreeNode root) {
    if (root == null) return;
    // postorder
    flatten(root.right);
    flatten(root.left);
    root.right = head;
    root.left = null;
    head = root;
  }
}