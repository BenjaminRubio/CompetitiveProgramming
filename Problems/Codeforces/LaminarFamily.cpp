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

struct Node
{
    int v, s, lzv = 0;
    bool lz = false;
    Node() : v(-2), s(0) {}
    Node(int x) : v(x), s(1) {}
    Node(const Node &a, const Node &b) 
    {
        if (a.v == -2) { v = b.v, s = b.s; return; }
        if (b.v == -2) { v = a.v, s = a.s; return; }
        if (a.v == -1 || b.v == -1 || a.v != b.v) v = -1;
        else v = a.v;
        s = a.s + b.s;
    }
    Node(int x, int i, int j, const Node &b) { s = b.s, v = x; }
};

template <class node>
struct STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push(int u, int i, int j, int x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv = x;
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv = x;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, int v, int u, int i, int j)
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(int N) : n(N), st(N * 4 + 5)
    {
        vector<node> v(N, node(0));
        build(0, 0, n - 1, v);
    }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};

template <class ST, class node>
class HLD
{
    ST st;
    vi A, H, D, R, P;

    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }
    template <class OP>
    void path(int u, int v, OP op)
    {
        for (; R[u] != R[v]; v = A[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v);
            op(P[R[v]], P[v]);
        }
        if (D[u] > D[v]) swap(u, v);
        op(P[u], P[v]);
    }

public:
    HLD(vector<vi> &G, int n) : A(n), st(n), D(n), R(n), P(n)
    {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    void set(int v, const node &x) { st.set(P[v], x); }
    void update(int u, int v, const int& x)
    { path(u, v, [this, &x](int l, int r) { st.update(l, r, x); }); }
    node query(int u, int v)
    {
        node ans = node();
        path(u, v, [this, &ans](int l, int r) { ans = node(ans, st.query(l, r)); });
        return ans;
    }
};

int N, F, u, v, o;
vector<vi> G;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> F;

    G.resize(N);
    rep(_, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    HLD<STL<Node>, Node> hld(G, N);

    vector<pair<int, pii>> E;
    rep(_, F)
    {
        cin >> u >> v; u--, v--;
        E.eb(hld.query(u, v).s, mp(u, v));
    }

    sort(E.rbegin(), E.rend());

    int now = 1;
    for (auto &e : E)
    {
        tie(u, v) = e.ss;

        Node r = hld.query(u, v);
        if (r.v == -1) { cout << "No"; return 0; }
        hld.update(u, v, now); now++;
    }

    cout << "Yes\n";
}
