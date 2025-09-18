import shiv.*;
class TreeTravelLoop
{
    // Return a list containing the inorder traversal of the given tree
    ArrayList<Integer> inOrder(Node root)
    {
        Stack<Node> s = new Stack<>();
        ArrayList<Integer> arr = new ArrayList<>();
        while(true)
        {
            while(root != null)
            {
                s.push(root);
                root = root.left;
            }
            
            if(s.isEmpty())
                break;
            
            Node top = s.peek();
            s.pop();
            
            arr.add(top.data);
            
            if(top.right != null)
                root = top.right;
        }
        
        return arr;
    }
}