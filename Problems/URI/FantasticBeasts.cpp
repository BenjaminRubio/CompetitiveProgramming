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
#define debugmp(m)                                                                              \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

inline ll mod(ll x, ll m)
{
    return ((x %= m) < 0) ? x + m : x;
}
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

pair<ll, ll> CRT(vector<ll> &r, vector<ll> &m, int n)
{
    ll r1 = r[0], m1 = m[0];
    repx(i, 1, n)
    {
        ll r2 = r[i], m2 = m[i];
        ll g, x, y;
        g = gcdext(m1, m2, x, y);
        if ((r1 - r2) % g != 0)
            return {-1, -1};
        ll z = m2 / g;
        ll lcm = m1 * z;
        ll sol = add(mod(r1, lcm), m1 * mul(mod(x, z), mod((r2 - r1) / g, z), z), lcm);
        r1 = sol;
        m1 = lcm;
    }
    return {r1, m1};
}

int b, z, c;
vi inits;
graph patterns;
vector<bool> visited;
vector<vector<ll>> r, p;
vector<ll> current_r, current_p;

int main()
{
    cin >> b >> z;
    inits.assign(b, 0);
    patterns.assign(b, vi(z, 0));
    r.assign(b, vector<ll>(z, -1));
    p.assign(b, vector<ll>(z, -1));

    rep(i, b)
    {
        cin >> inits[i];
        rep(j, z) cin >> patterns[i][j];
    }

    rep(i, b)
    {
        visited.assign(z, false);
        c = inits[i];
        visited[c - 1] = true;
        r[i][c - 1] = 0;
        rep(j, 2 * z)
        {
            c = patterns[i][c - 1];
            if (visited[c - 1] == false)
            {
                visited[c - 1] = true;
                r[i][c - 1] = j + 1;
            }
            else if (p[i][c - 1] == -1)
            {
                p[i][c - 1] = j - r[i][c - 1] + 1;
            }
        }
    }

    // debugm(r);
    // debugm(p);

    current_r.resize(b);
    current_p.resize(b);

    pair<ll, ll> ans = {LLONG_MAX, LLONG_MAX};

    rep(i, z)
    {
        bool cont = true;
        ll check = -1;
        rep(j, b)
        {
            current_r[j] = r[j][i];
            current_p[j] = p[j][i];
            if (current_r[j] == -1)
            {
                cont = false;
                break;
            }
            if (current_p[j] == -1)
                check = current_r[j];
        }
        if (cont == false)
            continue;

        cont = true;
        if (check != -1)
        {
            // cerr << i << '\n';
            rep(j, b)
            {
                if (current_p[j] != -1 && (current_r[j] > check || current_r[j] % current_p[j] != check % current_p[j]))
                    cont = false;
                if (current_p[j] == -1 && current_r[j] != check)
                    cont = false;
                if (cont == false)
                    break;
            }
            if (cont == true)
            {
                ans = {check, i};
            }
            continue;
        }

        pair<ll, ll> aux = CRT(current_r, current_p, b);
        if (aux.first != -1 && aux.second != -1 && aux.first < ans.first)
            ans = {aux.first, i};
    }

    if (ans.first != LLONG_MAX && ans.second != LLONG_MAX)
        cout << ans.second + 1 << ' ' << ans.first << '\n';
    else
        cout << "*\n";
}