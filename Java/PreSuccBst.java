

class Solution {
    
    public static void findPreSuc(Node root, Node[] pre, Node[] succ, int key) {
        if(root == null)
            return;
        
        Node temp = root;
        while(temp!=null && temp.data != key)
        {
            if(temp.data < key)
            {
                pre[0] = temp;
                temp = temp.right;
            }
            else
            {
                succ[0] = temp;
                temp = temp.left;
            }
        }
        
        if(temp == null) return;
        
        Node leftTree = temp.left;
        while(leftTree != null)
        {
            pre[0] = leftTree;
            leftTree = leftTree.right;
        }
        
        Node rightTree = temp.right;
        while(rightTree != null )
        {
            succ[0] = rightTree;
            rightTree = rightTree.left;
        }
    }
}