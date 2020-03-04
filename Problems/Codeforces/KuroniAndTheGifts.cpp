#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> a, b;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;

        a.resize(n);
        rep(i, n) cin >> a[i];

        b.resize(n);
        rep(i, n) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        rep(i, n) cout << a[i] << ' ';
        cout << '\n';
        rep(i, n) cout << b[i] << ' ';
        cout << '\n';
    }
}