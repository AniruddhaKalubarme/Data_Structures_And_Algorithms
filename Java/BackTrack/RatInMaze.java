//{ Driver Code Starts
import java.util.*;

class RatInMaze {
    // Function to find all possible paths
    boolean isVisitable(int i, int j, ArrayList<ArrayList<Integer>> mat)
    {
        if(i>=0 && i < mat.size() && j>=0 && j<mat.size() && mat.get(i).get(j) == 1)
        {
            return true;
        }
        return false;
    }
    
    void Find(ArrayList<ArrayList<Integer>> mat, int i, int j, String ans, ArrayList<String> output)
    {
        if(i == mat.size()-1 && j == mat.size()-1)
        {
            output.add(ans);
            return;
        }
        
        mat.get(i).set(j, 0);
        if(isVisitable(i+1, j, mat))
        {
            // mat.get(i+1).set(j, 0);
            Find(mat, i+1, j, ans+'D', output);
            // mat.get(i+1).set(j, 1);
        }
        
        if(isVisitable(i, j-1, mat))
        {
            // mat.get(i).set(j-1, 0);
            Find(mat, i, j-1, ans+'L', output);
            // mat.get(i).set(j-1, 1);
        }
        
        if(isVisitable(i, j+1, mat))
        {
            // mat.get(i).set(j+1, 0);
            Find(mat, i, j+1, ans+'R', output);
            // mat.get(i).set(j+1, 1);
        }
        
        if(isVisitable(i-1, j, mat))
        {
            // mat.get(i-1).set(j, 0);
            Find(mat, i-1, j, ans+'U', output);
            // mat.get(i-1).set(j, 1);
        }
        
        mat.get(i).set(j, 1);
    }
    
    public ArrayList<String> findPath(ArrayList<ArrayList<Integer>> mat) {
        ArrayList<String> output = new ArrayList<>();
        if(mat.get(0).get(0) == 0)
            return output;
        String ans = "";
        Find(mat, 0, 0, ans, output);
        return output;
    }
}