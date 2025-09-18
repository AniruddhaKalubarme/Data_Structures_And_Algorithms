/*
class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}
*/

class Solution {
    
    Map<Integer, Integer> mapping(int in[])
    {
       Map<Integer, Integer> map = new HashMap<>();
       
       for(int i = 0; i<in.length; i++)
       {
           map.put(in[i], i);
       }
       
       return map;
    }
    
    Node Build(int in[], int pre[], Map<Integer, Integer> map, int arr[], int s, int e)
    {
        if(arr[0]>=in.length || s>e)
            return null;
        
        int ele = pre[arr[0]++];
        Node root = new Node(ele);
        
        root.left = Build(in, pre, map, arr, s, map.get(ele)-1);
        root.right = Build(in, pre, map, arr, map.get(ele)+1, e);
        
        return root;
    }
    
    public Node buildTree(int inorder[], int preorder[]) {
        Map<Integer, Integer> map = mapping(inorder);
        int arr[] = {0};
        return Build(inorder, preorder, map, arr, 0, inorder.length-1);
    }
}