import shiv.*;
class MaxDiameter {
    
    int height(Node node) {
        if(node == null)
        {
            return 0;
        }
        
        int left = height(node.left);
        int right = height(node.right);
        
        int max = Math.max(left, right)+1;
        return max;
    }
    
    int diameter(Node root) {
        if(root == null)
            return 0;
            
        int left = diameter(root.left);
        int right = diameter(root.right);
        int ht = height(root.left) + height(root.right)+1;
        
        return Math.max(left, Math.max(right, ht));
    }
    
}

// Approach 2
//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

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

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution g = new Solution();
            System.out.println(g.diameter(root));
            t--;

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


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
    
    int[] diameter2(Node root) {
        if(root == null)
        {
            int arr[] = new int[2];
            arr[0] = 0;
            arr[1] = 0;
            return arr;
        }
            
        int left[] = diameter2(root.left);
        int right[] = diameter2(root.right);
        
        int op1 = left[0];
        int op2 = right[0];
        int op3 = left[1] + right[1] + 1;
        
        int ans[] = new int[2];
        ans[0] = Math.max(op1, Math.max(op2, op3));
        ans[1] = Math.max(left[1], right[1]) + 1;
        
        return ans;
    }
    
    int diameter(Node root)
    {
        int arr[] = new int[2];
        arr = diameter2(root);
        return arr[0];
    }
}

