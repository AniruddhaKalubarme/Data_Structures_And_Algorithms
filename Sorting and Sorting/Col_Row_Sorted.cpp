#include <bits/stdc++.h>
using namespace std;

int main() {
	int row = 4, col = 5;
	// If columns and rows are sorted independently
	int arr[row][col] = {{1, 4, 5, 11, 15},
					     {2, 5, 8, 12, 19},
					     {3, 6, 9, 16, 22},
					     {10,13,14,17, 24}};

	int iRow = 0, iCol = col-1;
	int element = 12;
	while(iRow<row && iCol>=0)
	{
		if(arr[iRow][iCol] == element)
		{
			cout<<"[ "<<iRow<<" ] [ "<<iCol<<" ]";
			break;
		}

		if(element < arr[iRow][iCol])
			iCol--;
		else
			iRow++;
	}
	return 0;
}

/*
Another Approach

int iRow = row-1, iCol = 0;
	int element = 12;
	while(iRow>=0 && iCol<col)
	{
		if(arr[iRow][iCol] == element)
		{
			cout<<"[ "<<iRow<<" ] [ "<<iCol<<" ]";
			break;
		}

		if(element < arr[iRow][iCol])
			iRow--;
		else
			iCol++;
	}
*/