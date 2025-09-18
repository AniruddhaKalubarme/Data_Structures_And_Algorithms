class Solution {
    
    Map<Integer, Integer> mapping(int[] in)
    {
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i<in.length; i++)
        {
            map.put(in[i], i);
        }
        
        return map;
    }
    
    Node Build(int in[], int post[], Map<Integer, Integer> map, int arr[], int s, int e)
    {
        if(arr[0] < 0 || s>e)
            return null;
        
        int ele = post[arr[0]--];
        Node root = new Node(ele);
        
        root.right = Build(in, post, map, arr, map.get(ele)+1, e);
        root.left = Build(in, post, map, arr, s, map.get(ele)-1);
        
        return root;
    }
    
    Node buildTree(int[] inorder, int[] postorder) {
        Map<Integer, Integer> map = mapping(inorder);
        int arr[] = {inorder.length-1};
        return Build(inorder, postorder, map, arr, 0, inorder.length-1);
    }
}