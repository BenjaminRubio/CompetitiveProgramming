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

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9 + 7;
const int MAXN = 100010;

struct Node
{
    int v;
    Node() { v = 1e9; } // neutro
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = min(a.v, b.v); }
};

template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

vector<int> S;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

pll euclid(ll A, ll B)
{
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

ll minv(ll A, ll M)
{
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

ll F[MAXN];
ll choose(int n, int k)
{
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

ll divandconq(int i, int j, int mn, ST<Node> &st)
{
    if (i == j) return 1;

    int l = 0, r = j - i + 1;
    while (l < r)
    {
        int m = (l + r) / 2;

        int q = st.query(j - m, j).v;
        if (q == mn) r = m;
        else l = m + 1;
    }

    int p = j - l;
    if (p < i) return 0;

    // cerr << i << ' ' << j << ' ' << p << endl;

    ll ans = choose(j - i - 1, p - i);
    ans = mul(ans, mul(divandconq(i, p, mn, st), divandconq(p + 1, j, mn + 1, st)));

    return ans;
}

void test_case()
{
    int N; cin >> N;

    S.resize(N);
    rep(i, N) cin >> S[i];

    vector<Node> v;
    rep(i, N) v.eb(S[i]);

    ST<Node> st(v, N);

    int ans = divandconq(0, N, 1, st);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    F[0] = 1;
    for (int i = 1; i < MAXN; i++) F[i] = mul(i, F[i - 1]);

    int num_tests; cin >> num_tests;
    rep(test, num_tests)
    {
        cout << "Case #" << test + 1 << ": ";
        test_case();
    }
}
