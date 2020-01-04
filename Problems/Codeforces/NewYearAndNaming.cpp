#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m, q, y;
vector<string> s1, s2;

int main()
{
    cin >> n >> m;

    s1.resize(n);
    rep(i, n) cin >> s1[i];

    s2.resize(m);
    rep(i, m) cin >> s2[i];

    cin >> q;
    rep(i, q)
    {
        cin >> y;
        y--;
        cout << s1[y % n] << s2[y % m] << '\n';
    }
}