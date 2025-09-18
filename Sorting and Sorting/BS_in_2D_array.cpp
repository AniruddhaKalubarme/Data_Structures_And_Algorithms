#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	int row = 3, col = 3;
	int Arr[row][col] = {{1,5,6},{8,10,25},{36,58,69}};
	int target = 20;
	int s = 0, e = row*col - 1, mid = (s+e)/2;

	while(s<e)
	{
		if(Arr[mid/row][mid%col] == target)
		{
			cout<<"ELEMENT FOUND: [ "<<mid/row<<" ] [ "<<mid%col<<" ]"<<endl;
			break;
		}
		else if(target < Arr[mid/row][mid%col])
			e = mid-1;
		else
			s = mid+1;

		mid = (s+e)/2;
	}


	return 0;
}
