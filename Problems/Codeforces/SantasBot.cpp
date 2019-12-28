#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MOD = 998244353;

int n, k, x;
vector<vector<int>> a;

int main()
{
    cin >> n;
    a.assign(n, {});
    rep(i, n)
    {
        cin >> k;
        rep(j, k)
        {
            cin >> x;
            a[i].push_back(x);
        }
    }


}