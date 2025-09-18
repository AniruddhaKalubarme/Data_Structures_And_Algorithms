import java.util.*;

class Node {
    char data;
    Node[] children;
    boolean isTerm;
    int ChildCount;

    Node(char d) {
        data = d;
        children = new Node[26];
        for (int i = 0; i < 26; i++) {
            children[i] = null;
        }

        isTerm = false;
        ChildCount = 0;
    }
}

class TrieImplement {
    Node root = new Node('\0');

    void InsertWord(Node root, String str, int i) {
        if (i == str.length()) {
            root.isTerm = true;
            return;
        }
        int index = str.charAt(i) - 'a';
        char ch = str.charAt(i);

        if (root.children[index] == null) {
            root.ChildCount++;
            Node child = new Node(ch);
            root.children[index] = child;
        }

        InsertWord(root.children[index], str, i + 1);
    }

    void Insert(String word) {
        InsertWord(root, word, 0);
    }
}


class PrintSugg {
    public static void main(String[] arg) {
        TrieImplement obj = new TrieImplement();
        Scanner Sobj = new Scanner(System.in);

        System.out.println("If you want to stop inserting Words then Enter -1\n");

        while(true)
        {
            System.out.print("Enter the word: ");
            String str = Sobj.nextLine();
            if(str.equals("-1"))
                break;
            
            obj.Insert(str);
        }

        while(true)
        {
            System.out.print("\nEnter the word thar you want to search: ");
            String str = Sobj.nextLine();
            if(str.equals("-1"))
                break;
            PrintSuggestion obj1 = new PrintSuggestion();
            obj1.getSugg(obj.root, str);
        }
    }
}

class PrintSuggestion
{
    void getSugg(Node root, String word)
    {
        ArrayList<ArrayList<String>> Output = new ArrayList<>();
        String prefix = "";
        Node prev = root;

        for(int i = 0; i<word.length(); i++)
        {
            ArrayList<String> temp = new ArrayList<>();
            char lastch = word.charAt(i);
            prefix += lastch;
            Node curr = prev.children[lastch - 'a'];

            if(curr == null)
                break;

            Sugg(curr, prefix, temp);
            Output.add(temp);
            prev = curr;
        }

        for(int i = 0; i<Output.size(); i++)
        {
            for(int j = 0; j<Output.get(i).size(); j++)
            {
                System.out.print(Output.get(i).get(j)+" -> ");
            }

            System.out.println();
        }
    }

    void Sugg(Node root, String prefix, ArrayList<String> temp)
    {
        if(root.isTerm)
        {
            temp.add(prefix);
        }

        for(char ch = 'a' ; ch<='z'; ch++)
        {
            Node curr = root.children[ch-'a'];
            if(curr != null)
            {
                Sugg(curr, prefix+ch, temp);
            }
        }
    }
}