import java.io.*;
import java.math.*;
import java.util.*;


/*
class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}
*/
class Solution {
    ArrayList<Integer> Inorder(Node root, ArrayList<Integer> ans)
    {
        if(root == null)
            return ans;
            
        Inorder(root.left, ans);
        ans.add(root.data);
        Inorder(root.right, ans);
        
        return ans;
    }
    
    boolean FindPair(Node root, ArrayList<Integer> ans, int target)
    {
        int i = 0;
        int j = ans.size()-1;
        
        while(i<j)
        {
            int iSum = ans.get(i) + ans.get(j);
            if(iSum < target)
                i++;
            else if(iSum > target)
                j--;
            else
                return true;
        }
        
        return false;
    }
    
    boolean findTarget(Node root, int target) {
        ArrayList<Integer> ans = new ArrayList<>();
        ans = Inorder(root, ans);
        return FindPair(root, ans, target);
    }
}
