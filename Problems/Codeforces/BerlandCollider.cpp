#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int n;
vector<ll> p, v;

bool check(double t)
{
    double prev = -1e9;
    bool flag = false;
    rep(i, n)
    {
        double pos = p[i] + v[i] * t;
        if (v[i] > 0) prev = max(prev, pos), flag = true;
        else if (pos < prev && flag) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(12);

    cin >> n;

    p.resize(n); v.resize(n);
    rep(i, n) cin >> p[i] >> v[i];

    bool collision = false;
    double l = 0, r = 2e9, m;
    rep(_, 60)
    {
        m = (l + r) * .5;
        if (check(m)) r = m, collision = true;
        else l = m;
    }

    if (collision) cout << (l + r) * .5 << '\n';
    else cout << -1 << '\n';
}