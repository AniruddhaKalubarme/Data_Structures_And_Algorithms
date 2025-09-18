#include <bits/stdc++.h>

bool isSafe(int row, int col, int val, vector<vector<int>>& sudoku)
{
    for(int i = 0; i<9; i++)
    {
        if(sudoku[row][i] == val)
            return false;

        if(sudoku[i][col] == val)
           return false;

        if(sudoku[3*(row/3) +i/3][3*(col/3)+i%3] == val)
            return false;       
    }

    return true;
}

bool Solve(vector<vector<int>>& sudoku)
{
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                for(int k = 1; k<=9; k++)
                {
                    if(isSafe(i, j, k, sudoku))
                    {
                        sudoku[i][j] = k;
                        bool aglaSolution = Solve(sudoku);
                        if(aglaSolution)
                            return true;
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

// Approach 2 for Solve
bool Solve(vector<vector<int>>& sudoku, int i, int j)
{
    if(i == 9)
        return true;

    int nextRow = i;
    int nextCol = j+1;
    if(nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }


    if(sudoku[i][j] == 0)
    {
        for(int k = 1; k<=9; k++)
        {
            if(isSafe(i, j, k, sudoku))
            {
                sudoku[i][j] = k;
                bool aglaSolution = Solve(sudoku, nextRow, nextCol);
                if(aglaSolution)
                    return true;
                else
                {
                    sudoku[i][j] = 0;
                }
            }

        }
        return false;
    }

    Solve(sudoku, nextRow, nextCol);
}


void solveSudoku(vector<vector<int>>& sudoku)
{
	Solve(sudoku);
}