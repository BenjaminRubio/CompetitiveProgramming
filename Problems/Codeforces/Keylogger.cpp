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

const int MOD = 1e9 + 7;

struct Node
{
    int v;
    Node() { v = 0; }
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = (a.v + b.v) % MOD; }
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

int K, L, N;
vector<vi> T;
vi P;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> K >> L;

    T.assign(K, vi(K, 0));
    rep(i, K) rep(j, K) cin >> T[i][j];

    cin >> N;
    P.resize(N); rep(i, N - 1) cin >> P[i];

    vector<Node> arr(K);
    rep(i, K) arr[i] = Node(1);
    ST<Node> st(arr, K);

    for (int i = N - 2; i >= 0; i--)
    {
        rep(k, K)
        {
            int l = lower_bound(T[k].begin(), T[k].end(), P[i] - L) - T[k].begin();
            int r = upper_bound(T[k].begin(), T[k].end(), P[i] + L) - T[k].begin();

            arr[k] = st.query(l, r);
        }

        st = ST<Node>(arr, K);
    }

    cout << st.query(0, K).v << '\n';
}
