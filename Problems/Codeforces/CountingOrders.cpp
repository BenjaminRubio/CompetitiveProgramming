#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, p, v, k;
vector<vector<int>> g;

int main()
{
    cin >> n;

    g.resize(n);
    rep(i, n - 1)
    {
        cin >> p;
        g[p - 1].push_back(i);
    }
}