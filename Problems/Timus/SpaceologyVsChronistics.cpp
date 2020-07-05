#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, x, A, B;
vector<vector<ll>> G;

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x + m : x; }
inline ll mul(ll x, ll y, ll m) { return (x * y) % m; }
inline ll add(ll x, ll y, ll m) { return (x + y) % m; }

ll gcdext(ll a, ll b, ll& x, ll& y)
{
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1)
    {
        q = r2 / r1, r0 = r2 % r1;
        x0 = x2 - q * x1, y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;        
    }
    ll g = r2; x = x2, y = y2;
    if (g < 0) g = -g, x = -x, y = -y;
    return g;
}

pair<ll,ll> CRT(ll r1, ll m1, ll r2, ll m2)
{
    ll g, x, y; g = gcdext(m1, m2, x, y);
    if (g == 0) return {-1, -1};
    if ((r1 - r2) % g != 0) return {-1, -1};
    ll z = m2 / g;
    ll lcm = m1 * z;
    ll sol = add(mod(r1, lcm), m1*mul(mod(x,z),mod((r2-r1)/g,z),z), lcm);
    return {sol, lcm};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    G.assign(N, vector<ll>(2));
    rep(i, N)
    {
        cin >> G[i][0]; G[i][1] = --G[i][0];
        while (1)
        {
            cin >> x;
            if (!x) break;
            G[i][1] = x - 1;
        }
    }

    cin >> A >> B; A--, B--;

    if (A == B) { cout << 0 << '\n'; return 0; }
    rep(i, 10 * N)
    {
        A = G[A][0], B = G[B][1];
        if (A == B) { cout << i + 1 << '\n'; return 0; }
    }

    ll sA = A, sB = B, lA = 1, lB = 1;
    while (G[A][0] != sA) A = G[A][0], lA++;
    while (G[B][1] != sB) B = G[B][1], lB++;
    A = sA, B = sB;

    map<ll, ll> pA; pA[A] = 0; ll s = 0;
    while (G[A][0] != sA) { A = G[A][0]; pA[A] = ++s; }

    ll ans = LLONG_MAX; s = 0;
    if (pA.count(B))
    {
        pair<ll, ll> aux = CRT(s, lB, pA[B], lA);
        if (aux.first != -1) ans = min(ans, aux.first);
    }
    while (G[B][1] != sB)
    {
        B = G[B][1], s++;
        if (pA.count(B))
        {
            pair<ll, ll> aux = CRT(s, lB, pA[B], lA);
            if (aux.first != -1) ans = min(ans, aux.first);
        }
    }

    if (ans == LLONG_MAX) cout << -1 << '\n';
    else cout << 10 * N + ans << '\n';
}