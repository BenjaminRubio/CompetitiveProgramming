#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const ll MOD = 998244353;

int N, K, l, r;
vector<pair<pair<int, int>, int>> v;

inline ll mod(ll x) { return ((x %= MOD) < 0) ? x+MOD : x; }
inline ll mul(ll x, ll y) { return (x * y) % MOD; }

ll gcdext(ll a, ll b, ll& x, ll &y) {
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1) {
        q = r2 / r1;
        r0 = r2 % r1;
        x0 = x2 - q * x1;
        y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;        
    }
    ll g = r2; x = x2, y = y2;
    if (g < 0) g = -g, x = -x, y = -y;
    return g;
}

ll mulinv(ll a) {
    ll x, y;
    if (gcdext(a, MOD, x, y) == 1) return mod(x);
    return -1;
}

const int MAXN = 3e5;

ll fac[MAXN+1];
void init() {
    fac[0] = 1;
    rep(i, MAXN + 1) if (i) fac[i] = (i * fac[i-1]) % MOD;
}
ll choose_mod(int n, int k) {
    return mul(fac[n], mulinv(mul(fac[k], fac[n-k])));
}

int main()
{
    cin >> N >> K;

    init();

    v.resize(2 * N);
    rep(i, N) 
    {
        cin >> l >> r;
        v[2 * i].ff.ff = l, v[2 * i].ff.ss = 0; v[2 * i].ss = i;
        v[2 * i + 1].ff.ff = r, v[2 * i + 1].ff.ss = 1; v[2 * i + 1].ss = i;
    }

    sort(v.begin(), v.end());

    ll ans = 0, c = 0;
    for (auto &e : v)
    {
        if (e.ff.ss == 0) c++;
        if (e.ff.ss == 1) c--;
        if (e.ff.ss == 0 && c >= K)
        {
            ans = mod(ans + choose_mod(c - 1, K - 1));
            // cerr << ans << '\n';
        }
    }

    cout << ans << '\n';
}