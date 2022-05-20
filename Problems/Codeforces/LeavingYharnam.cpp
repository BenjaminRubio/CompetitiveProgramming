#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int MAXN = 1000010;
const ll MOD = 1e9 + 7;

ll N, G, I, E, F[MAXN], P[MAXN];

inline ll add(ll x, ll y) { return (x + y) % MOD; }
inline ll mul(ll x, ll y) { return (x * y) % MOD; }

pll euclid(ll A, ll B)
{
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

ll minv(ll A)
{
    pll p = euclid(A, MOD);
    assert(p.ff * A + p.ss * MOD == 1);
    return p.ff + (p.ff < 0) * MOD;
}

ll C(int n, int k) { return mul(F[n], minv(mul(F[k], F[n - k]))); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    F[0] = 1, P[0] = 1;
    rep(i, MAXN - 1) F[i + 1] = mul(i + 1, F[i]), P[i + 1] = mul(2, P[i]);

    cin >> N >> G >> I >> E;

    ll S = 0, T = 0;

    if (E + G + I >= 2 * N)
    {
        cout << min(2 * N, E + G) << '\n';
        return 0;
    }

    repx(p, max(0ll, G - N), G / 2 + 1)
    {
        ll o = G - 2 * p, c = N - p - o;
        if (c < 0) continue;

        ll s = G, t = mul(C(N, p), mul(C(N - p, o), P[o]));

        if (E <= o) s += E, o -= E;
        else
        {
            ll pp = (E - o) / 2, oo = (E - o) & 1ll;
            s += E, o = oo, c -= pp + o;
            if (o == 1 && I <= c) s--;
        }

        ll oo = min(c, I) - max(0ll, I - c - o); s += oo;

        S = add(S, mul(s, t)), T = add(T, t);
    }

    cout << mul(S, minv(T)) << '\n';
}
