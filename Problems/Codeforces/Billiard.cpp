#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<float> vfloat;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = a; i > (int)b; i--)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) // cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //                                                                       \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x + m : x; }
inline ll mul(ll x, ll y, ll m) { return (x * y) % m; }
inline ll add(ll x, ll y, ll m) { return (x + y) % m; }

ll gcdext(ll a, ll b, ll &x, ll &y)
{
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1)
    {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;
    }
    ll g = r2;
    x = x2, y = y2;
    if (g < 0)
        g = -g, x = -x, y = -y;
    return g;
}

pair<ll, ll> CRT(ll r1, ll m1, ll r2, ll m2)
{
    ll g, x, y;
    g = gcdext(m1, m2, x, y);
    if ((r1 - r2) % g != 0)
        return {-1, -1};
    ll z = m2 / g;
    ll lcm = m1 * z;
    ll sol = add(mod(r1, lcm), m1 * mul(mod(x, z), mod((r2 - r1) / g, z), z), lcm);
    return {sol, lcm};
}

ll n, m, x, y, vx, vy;

int main()
{
    cin >> n >> m >> x >> y >> vx >> vy;

    if ((vx == 0 && x % n != 0) || (vy == 0 && y % m != 0))
    {
        cout << -1 << '\n';
        return 0;
    }

    if (vx == 0 || vy == 0)
    {
        if (vy == 1)
            cout << x << ' ' << m << '\n';
        if (vy == -1)
            cout << x << ' ' << 0 << '\n';
        if (vx == 1)
            cout << n << ' ' << y << '\n';
        if (vx == -1)
            cout << 0 << ' ' << y << '\n';
        return 0;
    }

    if ((x == 0 && vx == -1) || (x == n && vx == 1))
        vx *= -1;
    if ((y == 0 && vy == -1) || (y == m && vy == 1))
        vy *= -1;

    ll r1, r2;
    if (vx == -1 && vy == -1)
    {
        r1 = x;
        r2 = y;
    }
    if (vx == -1 && vy == 1)
    {
        r1 = x;
        r2 = m - y;
    }
    if (vx == 1 && vy == 1)
    {
        r1 = n - x;
        r2 = m - y;
    }
    if (vx == 1 && vy == -1)
    {
        r1 = n - x;
        r2 = y;
    }

    pair<ll, ll> ans = CRT(r1, n, r2, m);
    
    if (ans.first == -1 && ans.second == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    ll sol = ans.first;
    ll k1 = (sol - r1) / n;
    ll k2 = (sol - r2) / m;

    if (k1 % 2)
        vx *= -1;
    if (k2 % 2)
        vy *= -1;

    if (vx == -1 && vy == -1)
        cout << 0 << ' ' << 0 << '\n';
    if (vx == -1 && vy == 1)
        cout << 0 << ' ' << m << '\n';
    if (vx == 1 && vy == 1)
        cout << n << ' ' << m << '\n';
    if (vx == 1 && vy == -1)
        cout << n << ' ' << 0 << '\n';
}