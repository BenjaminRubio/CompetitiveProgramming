#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Node
{
    int v;
    Node() { v = -1; }
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = (a.v != -1 ? a.v : b.v); }
};

template <class node>
struct ST
{
    vector<node> t; int n;

    ST(int n) : n(n), t(n * 2) {}
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

template <class ST, class node>
class HLD
{
    ST st;
    vector<int> A, H, D, R, P;

    int dfs(vector<vector<int>> &G, int u)
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
            op(P[R[v]], P[v] + 1);
        }
        if (D[u] > D[v]) swap(u, v);
        op(P[u], P[v] + 1);
    }

public:
    HLD(vector<vector<int>> &G, int n) : A(n), st(n), D(n), R(n), P(n)
    {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    node get(int u) { return st.query(P[u], P[u] + 1); }
    void set(int u, const node &x) { st.set_point(P[u], x); }
    node query(int u, int v)
    {
        node ans = node();
        path(u, v, [this, &ans](int l, int r) { ans = node(st.query(l, r), ans); });
        return ans;
    }
};

int N, Q, u, v, s;
vector<vector<int>> G;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;

    G.assign(N, {});
    rep(i, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    HLD<ST<Node>, Node> hld(G, N);

    while (Q--)
    {
        cin >> s >> u; u--;
        if (s == 0)
        {
            Node n = hld.get(u), nn;
            if (n.v == -1) nn = Node(u + 1);
            hld.set(u, nn);
        }
        if (s == 1) cout << hld.query(0, u).v << '\n';
    }
}