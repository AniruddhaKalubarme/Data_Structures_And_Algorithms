#include <bits/stdc++.h>
using namespace std;

vector<double> Reverse(vector<double> v) {
    int s = 3;
    int e = v.size() - 1;

    while (s <= e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }

    return v;
}

int main() {
    vector<double> v1 = {1, 2, 3, 4, 5, 6, 7};

    vector<double> ans = Reverse(v1);

    for (double i : ans) {
        // cout << "i = " << sizeof(i) << endl;
        cout <<i << " ";
    }
}
