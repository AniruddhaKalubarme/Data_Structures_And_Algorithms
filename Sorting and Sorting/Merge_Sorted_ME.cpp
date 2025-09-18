#include<iostream>
#include<vector>
using namespace std;

vector <int> Merg_Sorted(vector <int> v1, vector <int> v2)
{
    vector<int> ans;
    int s1 = 0, s2 = 0;
    
    while(s1<v1.size() || s2<v2.size())
    {
        if(s1 >= v1.size())
        {
            ans.push_back(v2[s2]);
            s2++;
            continue;
        }
        if(s2 >= v2.size())
        {
            ans.push_back(v1[s1]);
            s1++;
            continue;
        }

        if(v1[s1]>=v2[s2])
        {
            ans.push_back(v2[s2]);
            s2++;
        }
        else if(v1[s1]<v2[s2])
        {
            ans.push_back(v1[s1]);
            s1++;
        }
        
    }
    return ans;
}

int main()
{
    vector <int> vec1,vec2,vec3;
    vec1 = {3,9,12,65,89,98,99};
    vec2 = {4,6,78,88};

    vec3 = Merg_Sorted(vec1, vec2);

    for(auto i:vec3)
    {
        cout<<i<<" ";
    }
    return 0;
}