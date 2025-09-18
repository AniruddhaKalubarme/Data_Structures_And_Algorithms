#include<iostream>
#include<queue>
using namespace std;

class solve
{
    deque<int> max;
    deque<int> min;
    int ans  = 0;

    public:
    int add(int *arr, int k, int n)
    {
        for(int i = 0; i<k; i++)
        {
            // Sort and add
            while(!max.empty() && arr[max.front()] <= arr[i])
            {
                max.pop_back();
            }

            while(!min.empty() && arr[min.front()] >= arr[i])
            {
                min.pop_back();
            }

            max.push_back(i);
            min.push_back(i);
        }

        ans += arr[max.front()] + arr[min.front()];
        for(int i = k; i<n; i++)
        {
            // Removel when window size is reached
            while(!max.empty() && max.front() - i >= k)
            {
                max.pop_front();
            }

            // Removel when window size is reached
            while(!min.empty() && min.front() - i >= k)
            {
                min.pop_front();
            }


            // Sort and add
            while(!max.empty() && arr[max.front()] <= arr[i])
            {
                max.pop_back();
            }

            while(!min.empty() && arr[min.front()] >= arr[i])
            {
                min.pop_back();
            }

            max.push_back(i);
            min.push_back(i);

            ans += arr[max.front()] + arr[min.front()];
        }

        return ans;
    }
};

int main()
{
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;

    solve obj;
    cout<<obj.add(arr, k, 7)<<endl;
    return 0;
}