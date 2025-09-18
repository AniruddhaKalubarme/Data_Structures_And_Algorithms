#include<vector>
#include <climits>

int kSorted(vector<vector<int>> &a, int k, int n) {
    vector<int> column(k,0);
    

    int range = INT_MAX;
    for(; ;)
    {
        int iMin = INT_MAX;
        int iMax = INT_MIN;
        int minIndex = -1;

        for(int i = 0; i<k; i++)
        {
            iMin = min(iMin, a[i][column[i]]);
            if(iMin == a[i][column[i]])
                minIndex = i;
            iMax = max(iMax, a[i][column[i]]);
        }

        column[minIndex]++;
        range = min(range, abs(iMax-iMin) + 1);
        if(column[minIndex] == n)
            break;
    }

    return range;
}



// Approach - 2
#include<vector>
#include <climits>
#include<queue>

class Node{
    public:
    int data;
    int i,j;
    Node(int d, int i, int j):data(d), i(i), j(j){}
};

class compare
{
    public:
    bool operator()(Node o1, Node o2)
    {
        return o1.data>o2.data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node , vector<Node>, compare > pq;

    int range = INT_MAX;
    int iMax = INT_MIN;
    int iMin = INT_MAX;

    for(int i = 0; i<k; i++)
    {
        iMax = max(iMax, a[i][0]);
        pq.push(Node(a[i][0], i, 0));
    }

    while(!pq.empty())
    {
        Node top = pq.top();
        iMin = top.data;
        pq.pop();

        range = min(range, iMax-iMin+1);
        int i = top.i;
        int j = top.j; 
        if((top.j)+1<n)
        {
            iMax = max(iMax, a[i][j+1]);
            pq.push(Node(a[i][j+1], i, j+1));
        }
        else
            break;
    }
    return range;
}