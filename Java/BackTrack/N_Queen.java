class Solution {
    boolean Chk(int i, int j, int n, List<String> Board)
    {
        for(int k = 0; k<j; k++)
        {
            if(Board.get(i).charAt(k) == 'Q')
                return false;
        }

        int k = 1;
        while(i-k<n && i-k>=0 && j-k<n && j-k>=0)
        {
            if(Board.get(i-k).charAt(j-k) == 'Q')
                return false;
            k++;
        }

        k = 1;
        while(i+k<n && i+k>=0 && j-k<n && j-k>=0)
        {
            if(Board.get(i+k).charAt(j-k) == 'Q')
                return false;
            k++;
        }

        return true;
    }

    void Place(List<String> Board, int j, int n, List<List<String>> ans)
    {
        if(j == n)
        {
            ans.add(new ArrayList<>(Board));
            return;
        }
        
        for (int i = 0; i < n; i++) {
            char[] row = Board.get(i).toCharArray();

            if (Chk(i, j, n, Board)) {
                row[j] = 'Q';
                Board.set(i, new String(row));
                Place(Board, j + 1, n, ans);
                row[j] = '.';
                Board.set(i, new String(row));
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<String> Board = new ArrayList<>(n);
        List<List<String>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char[] row = new char[n];
            Arrays.fill(row, '.');
            Board.add(new String(row));
        }
        Place(Board, 0, n, ans);
        return ans;
    }
}