#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

struct SUM
{
    static ll const neutro = 0;
    static ll op(ll x, ll y) { return x + y; }
    static ll lazy_op(int i, int j, ll x) { return x * (j - i + 1); }
};

template <class t>
class STL
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        st[u] = t::lazy_op(i, j, x);
        if (i != j)
        {
            lazy[u * 2 + 1] = x;
            lazy[u * 2 + 2] = x;
        }
        lazy[u] = -1;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u] != -1) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, ll value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u] != -1) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

public:
    STL(vector<ll> &v)
    {
        arr = v; n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, -1);
        build(0, 0, n - 1);
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

const ll MOD = 1e9 + 7;

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x + m : x; }
inline ll mul(ll x, ll y, ll m) { return (x * y) % m; }
inline ll add(ll x, ll y, ll m) { return (x + y) % m; }

ll T, N, K, A, B, C, D;

int main()
{
    cin >> T;
    rep(test, T)
    {
        cout << "Case #" << test + 1 << ": ";

        cin >> N >> K;

        vector<ll> L(N), W(N), H(N), R(N);
        rep(i, K) cin >> L[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            L[i] = mod(mul(A, L[i - 2], D) + mul(B, L[i - 1], D) + mod(C, D), D) + 1ll;

        rep(i, K) cin >> W[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            W[i] = mod(mul(A, W[i - 2], D) + mul(B, W[i - 1], D) + mod(C, D), D) + 1ll;

        rep(i, K) cin >> H[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            H[i] = mod(mul(A, H[i - 2], D) + mul(B, H[i - 1], D) + mod(C, D), D) + 1ll;

        set<ll> s;
        rep(i, N) R[i] = L[i] + W[i], s.insert(L[i]), s.insert(R[i]);

        map<ll, ll> m; int id = 0;
        W.assign(s.size() + 1, 0);
        ll l = 0;
        for (ll x : s)
        {
            W[id] = x - l;
            m[x] = id++, l = x;
        }

        rep(i, N) L[i] = m[L[i]], R[i] = m[R[i]];

        vector<ll> n(s.size() + 1, 0);
        STL<SUM> stlw(W), stlh(n), stlv(n), stlt(n);

        ll ans = 1, P = 0;
        rep(i, N)
        {
            P = (P + 2ll * stlw.query(L[i] + 1, R[i])) % MOD;
            stlw.update(L[i] + 1, R[i], 0);

            ll tl = stlt.query(L[i], L[i]), tr = stlt.query(R[i], R[i]);
            ll l = H[i] - stlh.query(L[i], L[i]) + (tl != 2) * stlv.query(L[i], L[i]);
            ll r = H[i] - stlh.query(R[i], R[i]) + (tr != 1) * stlv.query(R[i], R[i]);
            P = (P + l + r) % MOD;
            stlh.update(L[i], R[i], H[i]);

            P = (P - stlv.query(L[i], R[i])) % MOD;
            stlv.update(L[i], R[i], 0);
            stlv.update(L[i], L[i], l);
            stlv.update(R[i], R[i], r);

            stlt.update(L[i], R[i], 0);
            stlt.update(L[i], L[i], 1);
            stlt.update(R[i], R[i], 2);

            ans = (ans * P) % MOD;
        }

        cout << (ans + MOD) % MOD << '\n';
    }
}