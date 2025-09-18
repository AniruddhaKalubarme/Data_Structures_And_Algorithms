// Approach -1 
#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> ans;
	for(int i = 0; i<arr.size(); i++)
	{
		int iSum = 0;
		for(int j = i; j<arr.size(); j++)
		{
			iSum+=arr[j];
			ans.push_back(iSum);
		}
	}

	sort(ans.begin(), ans.end());

	return ans[ans.size()-k];
}

// Approach - 2
#include<algorithm>
#include<queue>
#include<vector>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 0; i<arr.size(); i++)
	{
		int iSum = 0;
		for(int j = i; j<arr.size(); j++)
		{
			iSum+=arr[j];
			if(pq.size()<k)
			{
				pq.push(iSum);
			}
			else
			{
				if(pq.top()<iSum)
				{
					pq.pop();
					pq.push(iSum);
				}
			}
		}
	}

	return pq.top();

}