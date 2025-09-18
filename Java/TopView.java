//{ Driver Code Starts
// Initial Template for JAVA

import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;


// } Driver Code Ends
// User function Template for Java

/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

class pair
{
    Node first;
    int second;
    
    public pair(Node first, int second)
    {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    void Solve(Node root, SortedMap<Integer, Integer> visited)
    {
        if(root == null)
            return;
        
        int hd = 0;
        Queue<pair> q = new LinkedList<>();
        pair obj = new pair(root, hd);
        q.add(obj);
        
        while(!q.isEmpty())
        {
            pair front = q.poll();
            
            if(!visited.containsKey(front.second))    
            {
                visited.put(front.second, front.first.data);
            }
            
            
            if(front.first.left != null)
            {
                pair temp = new pair(front.first.left,front.second-1);
                q.add(temp);
            }
             
            if(front.first.right != null)
            {
                pair temp = new pair(front.first.right,front.second+1);
                q.add(temp);
            }   
        }
        
    }
    
    ArrayList<Integer> topView(Node root) {
        SortedMap<Integer, Integer> visited = new TreeMap<>();
        Solve(root, visited);
        
        ArrayList<Integer> ans = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : visited.entrySet())
        {
            ans.add(entry.getValue());
        }
        
        return ans;
    }
}
