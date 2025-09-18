import java.util.*;

class Trie {
    public static void main(String[] arg) {
        TrieImplement obj = new TrieImplement();
        obj.Insert("anir");
        obj.Insert("aniru");
        obj.Insert("anira");

        // obj.Find("anir");
        // obj.Find("ani");

        // obj.Insert("ani");
        // obj.Find("ani");
        obj.Delete("aniru");
        obj.Delete("anira");
        obj.Delete("anir");
        obj.Find("anir");
    }
}

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

    boolean FindWord(Node root, String str, int i) {
        if (i == str.length()) {
            return root.isTerm;
        }

        char ch = str.charAt(i);
        int index = ch - 'a';

        if (root.children[index] == null) {
            return false;
        }

        return FindWord(root.children[index], str, i + 1);
    }

    void Find(String word) {
        if (FindWord(root, word, 0)) {
            System.out.println("Word exists");
        } else {
            System.out.println("Word does not exist");
        }
    }

    boolean DeleteWord(Node root, String word, int i)
    {
        if(i == word.length())
        {
            if(!root.isTerm)
            {
                return false;
            }

            root.isTerm = false;
            return root.ChildCount == 0;
        }

        int index = word.charAt(i) - 'a';
        Node child = root.children[index];
        if (child == null) return false;

        boolean ShouldBeDeleted = DeleteWord(child, word, i+1);
        if(ShouldBeDeleted)
        {
            root.children[index] = null;
            root.ChildCount--;
            return !root.isTerm && root.ChildCount == 0;
        }

        return false;

    }

    void Delete(String word)
    {
        if(FindWord(root, word, 0))
        {
            DeleteWord(root, word, 0);
            System.out.println("Successfully deleted the word");
        }
        else
        {
            System.out.println("Word not found");
        }
    }
}

