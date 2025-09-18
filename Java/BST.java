import java.util.*;

class Node
{
    int data;
    Node left, right;
    // Node (){}
    Node(int data)
    {
        this.data = data;
        left = right = null;
    }
}

class BST
{
    Scanner sobj = new Scanner(System.in);
    Node Construct(Node root, int x)
    {
        if(root == null)
        {
            Node newn = new Node(x);
            return newn;
        }

        if(x<root.data)
            root.left = Construct(root.left, x);
        else
            root.right = Construct(root.right, x);

        return root;
    }

    Node Insert()
    {
        Node root = null;
        while(true)
        {
            System.out.print("Enter the data: ");
            int data = sobj.nextInt();
            if(data == -1)
                break;
            
            root = Construct(root, data);
        }

        return root;
    }

    void Display(Node root)
    {
        if(root == null)
            return;
        
        Display(root.left);
        System.out.print(root.data+" -> ");
        Display(root.right);
    }

    public static void main(String arg[])
    {
        BST obj = new BST();

        Node root = obj.Insert();
        obj.Display(root);
    }
}