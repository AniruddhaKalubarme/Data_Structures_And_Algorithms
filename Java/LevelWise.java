package shiv;
import shiv.*;

import java.util.*;

class temp
{
    Queue<Node> q = new LinkedList<>();

    void Display(Node root)
    {
        if(root == null)
            return;
        
        q.add(root);

        while(!q.isEmpty())
        {
            Node front = q.peek();
            q.remove();

            System.out.print(front.data + " -> ");

            if(front.left != null)
                q.add(front.left);
            
            if(front.right != null)
                q.add(front.right);
        }
    }
}

public class LevelWise
{
    public static void main(String arg[])
    {
        Tree obj = new Tree();
        Node root = obj.Insert();
        // obj.Display(root);
        temp lvl = new temp();
        lvl.Display(root);
        
    }
}