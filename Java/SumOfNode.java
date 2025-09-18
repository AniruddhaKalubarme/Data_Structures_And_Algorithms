/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    
    void Solve(Node root, int k, ArrayList<Integer> arr, int iCnt[])
    {
        if(root == null) return;
        
        arr.add(root.data);
        
        int iSum = 0;
        for(int i = arr.size()-1; i>=0; i--)
        {
            iSum+=arr.get(i);
            if(iSum == k)
                iCnt[0]++;
        }
        
        Solve(root.left, k, arr, iCnt);
        Solve(root.right, k, arr, iCnt);
        
        arr.remove(arr.size()-1);
    }
    
    public int sumK(Node root, int k) {
        int ans[] = new int[1];
        ArrayList<Integer> arr = new ArrayList<>();
        Solve(root, k, arr, ans);
        return ans[0];
    }
}