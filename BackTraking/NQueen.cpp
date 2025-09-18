// Approach - 1: USING LOOPS (worst)
#include <bits/stdc++.h> 

void addSol(vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
	vector<int> temp;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

bool isSafe(int row, int col, int n, vector<vector<int>> board)
{
	int x=col;
	int y=row;

	while(x>-1)
	{
		if(board[y][x--] == 1)
			return false;
	}

	x = col;
	y = row;

	while(x>-1 && y>-1)
	{
		if(board[y--][x--] == 1)
			return false;
	}
	
	x = col;
	y = row;

	while(y<n && x>-1)
	{
		if(board[y++][x--] == 1)
			return false;
	}
	return true;
}

void Find(int col, vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
	if(col == n)
	{
		addSol(ans, board, n);
		return;
	}

	for(int row = 0; row < n; row++)
	{
		if(isSafe(row, col, n, board))
		{
			board[row][col] = 1;
			Find(col+1, ans, board, n);
			board[row][col] = 0;
		}

	}
	
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	Find(0, ans, board, n);

	return ans;	
}

// Approach - :- USING MAP (AVG)
#include <bits/stdc++.h> 

void addSol(vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
	vector<int> temp;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

void Find(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, map<int, int> &UpperDiag, map<int,int> &LowerDiag, vector<int> &isRowOcc)
{
	if(col == n)
	{
		addSol(ans, board, n);
		return;
	}

	for(int row = 0; row < n; row++)
	{
		if((LowerDiag[row+col] != 1 && UpperDiag[n-1 + col - row] != 1 && isRowOcc[row] != 1))
		{
			LowerDiag[row+col] = 1;
			UpperDiag[n-1+col-row] = 1;
			board[row][col] = 1;
			isRowOcc[row] = 1;

			Find(col+1, ans, board, n, UpperDiag, LowerDiag, isRowOcc);

			LowerDiag[row+col] = 0;
			UpperDiag[n-1+col-row] = 0;
			board[row][col] = 0;
			isRowOcc[row] = 0;
		}

	}
	
}

vector<vector<int>> nQueens(int n)
{
	map<int, int> UpperDiag, LowerDiag;
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	vector<int> isRowOcc(n,0);
	Find(0, ans, board, n, UpperDiag, LowerDiag, isRowOcc);

	return ans;	
}

// Approach-3 :- USING VECTORS (BEST)
#include <bits/stdc++.h> 

void addSol(vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
	vector<int> temp;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

void Find(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, vector<int> &UpperDiag, vector<int> &LowerDiag, vector<int> &isRowOcc)
{
	if(col == n)
	{
		addSol(ans, board, n);
		return;
	}

	for(int row = 0; row < n; row++)
	{
		if((LowerDiag[row+col] != 1 && UpperDiag[n-1 + col - row] != 1 && isRowOcc[row] != 1))
		{
			LowerDiag[row+col] = 1;
			UpperDiag[n-1+col-row] = 1;
			board[row][col] = 1;
			isRowOcc[row] = 1;

			Find(col+1, ans, board, n, UpperDiag, LowerDiag, isRowOcc);

			LowerDiag[row+col] = 0;
			UpperDiag[n-1+col-row] = 0;
			board[row][col] = 0;
			isRowOcc[row] = 0;
		}

	}
	
}

vector<vector<int>> nQueens(int n)
{
	vector<int> UpperDiag(n*2, 0), LowerDiag(n*2, 0);
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	vector<int> isRowOcc(n,0);
	Find(0, ans, board, n, UpperDiag, LowerDiag, isRowOcc);

	return ans;	
}