#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second
typedef long long ll;

int n;
vector<ll> m;
vector<ll> l, r, cl, cr;

int main()
{
    cin >> n;

    m.resize(n); l.resize(n); r.resize(n); cl.resize(n); cr.resize(n);
    rep(i, n) cin >> m[i];

    stack<pair<ll, int>> sl, sr;

    rep(i, n)
    {
        int aux = 1;
        bool done = false;
        while (!sl.empty() and sl.top().ff > m[i]) aux = i - sl.top().ss, sl.pop(), done = true;
        if (done) l[i] = l[i - aux] - cl[i - aux] * m[i - aux] + (aux + cl[i - aux]) * m[i], cl[i] = cl[i - aux] + aux;
        else if (i) l[i] = l[i - 1] + m[i], cl[i] = 1;
        else l[i] = m[i], cl[i] = 1;
        sl.push({m[i], i});
    }

    rep(i, n)
    {
        int aux = 1;
        bool done = false;
        while (!sr.empty() and sr.top().ff > m[n - i - 1]) aux = sr.top().ss - (n - i - 1), sr.pop(), done = true;
        if (done) r[n - i - 1] = r[n - i - 1 + aux] - cr[n - i - 1 + aux] * m[n - i - 1 + aux] + (aux + cr[n - i - 1 + aux]) * m[n - i - 1], cr[n - i - 1] = cr[n - i - 1 + aux] + aux;
        else if (i) r[n - i - 1] = r[n - i] + m[n - i - 1], cr[n - i - 1] = 1;
        else r[n - i - 1] = m[n - i - 1], cr[n - i - 1] = 1;
        sr.push({m[n - i - 1], n - i - 1});
    }

    ll ans = -1;
    int id;
    rep(i, n) if (l[i] + r[i] - m[i] > ans)
    {
        ans = l[i] + r[i] - m[i];
        id = i;
    }

    vector<ll> v(n);
    v[id] = m[id];

    ll aux = m[id];
    repx(i, id + 1, n)
    {
        if (m[i] < aux) aux = m[i];
        v[i] = aux;
    }

    aux = m[id];
    rep(i, id)
    {
        if (m[id - i - 1] < aux) aux = m[id - i - 1];
        v[id - i - 1] = aux;
    }

    rep(i, n) cout << v[i] << ' ';
    cout << '\n';
}