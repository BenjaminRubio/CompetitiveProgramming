#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll V, x, y, mx, Mx, my, My, per, A, temp, p, l;
vector<pair<ll, ll>> P;
map<ll, ll> M, m;

int main()
{
    cin >> V;

    set<ll> sx;
    mx = LLONG_MAX, my = LLONG_MAX, Mx = LLONG_MIN, My = LLONG_MIN;
    rep(i, V)
    {
        cin >> x >> y;
        mx = min(x - 1, mx), my = min(y - 1, my);
        Mx = max(x + 1, Mx), My = max(y + 1, My);
        sx.insert(x - 1), sx.insert(x + 1);
        P.emplace_back(x, y);
    }

    for (ll x : sx) M[x] = LLONG_MIN, m[x] = LLONG_MAX;

    rep(i, V)
    {
        M[P[i].ff - 1] = max(M[P[i].ff - 1], P[i].ss + 1);
        M[P[i].ff + 1] = max(M[P[i].ff + 1], P[i].ss + 1);
        m[P[i].ff - 1] = min(m[P[i].ff - 1], P[i].ss - 1);
        m[P[i].ff + 1] = min(m[P[i].ff + 1], P[i].ss - 1);
    }

    per = 2ll * ((Mx - mx) + (My - my)), A = 0;

    ll p1, p2;

    temp = LLONG_MAX, p = m.begin()->ff, l = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        A -= (it->ff - p) * l;
        if (temp != LLONG_MAX) M[it->ff + 1] = max(M[it->ff + 1], temp + 1);
        temp = min(temp, it->ss);
        if (temp == my) { p1 = it->ff, it->ss = -1; break; }
        it->ss = temp, p = it->ff, l = it->ss;
    }

    temp = LLONG_MAX, p = m.rbegin()->ff, l = 0;;
    for (auto it = m.rbegin(); it != m.rend(); it++)
    {
        A -= (p - it->ff) * l;
        if (temp != LLONG_MAX) M[it->ff - 1] = max(M[it->ff - 1], temp + 1);
        temp = min(temp, it->ss);
        if (temp == my) { p2 = it->ff, it->ss = -1; break; }
        it->ss = temp, p = it->ff, l = it->ss;
    }

    A -= my * (p2 - p1);

    temp = LLONG_MIN, p = m.begin()->ff, l = 0;
    for (auto it = M.begin(); it != M.end(); it++)
    {
        A += (it->ff - p) * l;
        temp = max(temp, it->ss);
        if (temp == My) { p1 = it->ff; break; }
        it->ss = temp, p = it->ff, l = it->ss;
    }

    temp = LLONG_MIN, p = m.begin()->ff, l = 0;
    for (auto it = M.rbegin(); it != M.rend(); it++)
    {
        A += (p - it->ff) * l;
        temp = max(temp, it->ss);
        if (temp == My) { p2 = it->ff; break; }
        it->ss = temp, p = it->ff, l = it->ss;
    }

    A += My * (p2 - p1);

    cout << per << ' ' << A << '\n';
}