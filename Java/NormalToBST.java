/*
class Node
{
    int data;
    Node right, left;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}*/



class Solution {
    void Inorder(Node root, ArrayList<Integer> ans)
    {
        if(root == null)
            return;
            
        Inorder(root.left, ans);
        ans.add(root.data);
        Inorder(root.right, ans);
    }
    
    Node Construct(Node root, ArrayList<Integer> ans, int s, int e)
    {
        if(s>e)
            return root;
            
        int mid = (s+e)/2;
        
        if(root == null)
        {
            root = new Node(ans.get(mid));
        }
        
            
        root.left = Construct(root.left, ans, s, mid-1);
        root.right = Construct(root.right, ans, mid+1, e);
        return root;
        
    }
    
    Node balanceBST(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        Inorder(root, ans);
        root = null;
        return Construct(root, ans, 0, ans.size()-1);
    }
}
