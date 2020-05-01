#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, k, n;
vector<int> a, b, c;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        b.clear(); c.clear();

        cin >> n >> k;
        a.resize(n);
        rep(i, n) cin >> a[i];

        set<int> cnt;
        rep(i, n) cnt.insert(a[i]);

        if (cnt.size() > k)
        {
            cout << -1 << '\n';
            continue;
        }

        for (int x : cnt) c.push_back(x);
        while (c.size() < k) c.push_back(*cnt.begin());

        cout << k * n << '\n';
        rep(i, n) for (int x : c) cout << x << ' ';
        cout << '\n';
    }
}