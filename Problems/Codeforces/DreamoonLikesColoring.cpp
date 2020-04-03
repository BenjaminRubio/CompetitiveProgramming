#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m;
vector<int> l;

int main()
{
    cin >> n >> m;

    long long s = 0;
    bool pos = true;
    l.resize(m);
    rep(i, m)
    {
        cin >> l[i];
        s += l[i];
        if (l[i] > n - i) pos = false;
    }

    if (!pos || s < n)
    {
        cout << -1 << '\n';
        return 0;
    }

    int t = n;
    vector<int> ans(m);
    rep(i, m)
    {
        t = min(n - l[m - i - 1] + 1, t);
        ans[m - i - 1] = t; t--;
    }

    t = 0;
    rep(i, m)
    {
        t = min(t + (i ? l[i - 1] : 1), ans[i]);
        cout << t << ' ';
    }
    cout << '\n';
}