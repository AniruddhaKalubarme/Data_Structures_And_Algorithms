#include <bits/stdc++.h> 

void sort(stack<int> &stac, int x)
{
	if(stac.empty() || stac.top()<x)
	{
		stac.push(x);
		return;
	}

	int num = stac.top();
	stac.pop();

	sort(stac, x);
	
	stac.push(num);
}

void sortStack(stack<int> &stac)
{
	if(stac.empty())
	{
		return;
	}

	int num = stac.top();
	stac.pop();
	sortStack(stac);
	sort(stac, num);
}