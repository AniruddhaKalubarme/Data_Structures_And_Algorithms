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

    TreeNode Mapping(TreeNode root, Map<TreeNode, TreeNode> childToParent, int target)
    {
        if(root == null)    return null;

        TreeNode temp = null;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        childToParent.put(root,null);

        while(!q.isEmpty())
        {
            TreeNode front = q.poll();

            if(front.val == target)
                temp = front;

            if(front.left != null)
            {
                childToParent.put(front.left,front);
                q.add(front.left);
            }

            if(front.right != null)
            {
                childToParent.put(front.right,front);
                q.add(front.right);
            }
        }

        return temp;
    }

    int TimeTaken(TreeNode root, Map<TreeNode, TreeNode> childToParent)
    {
        if(root == null)
            return -1;
        
        Queue<TreeNode> q = new LinkedList<>();
        Map<TreeNode, Boolean> visited = new HashMap<>();
        q.add(root);
        visited.put(root, true);
        int count = 0;
        int tag = 0;

        while(!q.isEmpty())
        {
            int size = q.size();
            tag = 0;
            for(int i = 0; i<size; i++)
            {
                TreeNode front = q.poll();
                if(front.left != null && (visited.containsKey(front.left) == false || visited.get(front.left) == false))
                {
                    tag = 1;
                    visited.put(front.left,true);
                    q.add(front.left);
                }

                if(front.right != null && (visited.containsKey(front.right) == false || visited.get(front.right) == false))
                {
                    tag = 1;
                    visited.put(front.right,true);
                    q.add(front.right);
                }

                if(childToParent.get(front) != null && (visited.containsKey(childToParent.get(front)) == false || visited.get(childToParent.get(front)) == false))
                {
                    tag = 1;
                    visited.put(childToParent.get(front), true);
                    q.add(childToParent.get(front));
                }
            }

            if(tag == 1)
                count++; 

        }

        return count;

    }

    public int amountOfTime(TreeNode root, int start) {
        Map<TreeNode, TreeNode> childToParent = new HashMap<>();
        root = Mapping(root, childToParent, start);
        return TimeTaken(root, childToParent);
    }
}