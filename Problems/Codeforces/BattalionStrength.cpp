#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const ll MOD = 1e9 + 7;
ll P[300001];

struct Node
{
    ll v, vl, vr, s;
    Node() : v(0), vl(0), vr(0), s(0) {}
    Node(int x) : v(0), vl(x), vr(x), s(1) {}
    Node(const Node &a, const Node &b)
    {
        v = (a.v * P[b.s] + b.v * P[a.s] + a.vl * b.vr) % MOD;
        vl = (a.vl + P[a.s] * b.vl) % MOD;
        vr = (b.vr + P[b.s] * a.vr) % MOD;
        s = a.s + b.s;
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1; )
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

int N, Q, i, j, x;
vector<int> p;
vector<pair<int, int>> v;
vector<Node> a;

ll inv(ll a)
{
    ll ans = 1, p = MOD - 2;
    for (; p; p >>= 1ll, a = (a * a) % MOD)
        if (p & 1ll) ans = (ans * a) % MOD;
    return ans;
}

int main()
{
    P[0] = 1;
    rep(i, 300000) P[i + 1] = (P[i] * 2ll) % MOD;

    cin >> N; p.resize(N);
    rep(i, N) { cin >> x; p[i] = x; v.emplace_back(x, i); }

    cin >> Q; queue<pair<int, int>> q;
    rep(j, Q) { cin >> i >> x; q.emplace(i - 1, N + j); v.emplace_back(x, N + j); }

    sort(v.begin(), v.end());

    map<int, int> m; a.resize(N + Q);
    rep(i, N + Q)
    {
        if (v[i].ss < N) a[i] = Node(v[i].ff);
        m[v[i].ss] = i;
    }

    ST<Node> st(a);

    cout << (st.query(0, N + Q).v * inv(P[N])) % MOD << '\n';
    while (!q.empty())
    {
        tie(i, j) = q.front(); q.pop();
        st.set_point(m[i], Node()), st.set_point(m[j], Node(v[m[j]].ff));
        m[i] = m[j];
        
        cout << (st.query(0, N + Q).v * inv(P[N])) % MOD << '\n';
    }
}