package shiv;
import java.util.Scanner;

class Node
{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

class Tree
{

    Scanner sobj = new Scanner(System.in);

    Node Insert()
    {
        System.out.print("Enter the root data: ");
        int data = sobj.nextInt(); //

        if(data == -1)
            return null;

        Node root = new Node(data);
        
        System.out.println("Enter the left of "+data+": ");
        root.left = Insert();

        System.out.println("Enter the right of "+data+": ");
        root.right = Insert();

        return root;
    }

    void Display(Node root)
    {
        if(root == null)
        {
            return;
        }

        Display(root.left);
        System.out.print(root.data+" -> ");
        Display(root.right);
    }
}


/*
import java.util.Scanner;

class Node
{
    int data;
    Node left;
    Node right;

    Node(){}

    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

class Tree
{

    Scanner sobj = new Scanner(System.in);

    Node Insert(Node root)
    {
        System.out.print("Enter the root data: ");
        int data = sobj.nextInt(); //

        if(data == -1)
            return null;

        Node newn = new Node(data);
        root = newn;
        
        System.out.println("Enter the left of "+data+": ");
        root.left = Insert(root);

        System.out.println("Enter the right of "+data+": ");
        root.right = Insert(root);

        return root;
    }

    void Display(Node root)
    {
        if(root == null)
        {
            return;
        }

        Display(root.left);
        System.out.print(root.data+" -> ");
        Display(root.right);
    }
}

public class temp
{
    public static void main(String arg[])
    {
        Tree obj = new Tree();
        Node root = new Node();
        root = obj.Insert(root);
        obj.Display(root);
    }
}
*/