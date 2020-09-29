#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    int v, l, r;
    Node() : v(0), l(0), r(0) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    { v = a.v + b.v; }
};

template <class node>
struct PST
{
    int cnt = 1, n, rc = 1; node na, nb;
    vector<node> st; vector<int> rt;

    node query(int u, int a, int b, int i, int j)
    {
        if (j < a || b < i) return node();
        if (a <= i && j <= b) return st[u];
        int m = (i + j) / 2, l = st[u].l, r = st[u].r;
        return node(query(l, a, b, i, m), query(r, a, b, m + 1, j), l, r);
    }
    int update(int u, int p, node v, int i, int j)
    {
        if (j < p || p < i) return u;
        st[cnt] = st[u]; int x = cnt++, m = (i + j) / 2;
        if (i == j) { st[x] = v; return x; }
        int l = st[x].l = update(st[x].l, p, v, i, m);
        int r = st[x].r = update(st[x].r, p, v, m + 1, j);
        st[x] = node(st[l], st[r], l, r); return x;
    }

    PST(int N) : st(2e6), rt(2e5), n(N) {}
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }

    int search_(int k, int i, int j)
    {
        if (i == j) return i;
        int m = (i + j) / 2, v = st[nb.l].v - st[na.l].v;
        if (v >= k)
        {
            na = st[na.l], nb = st[nb.l];
            return search_(k, i, m);
        }
        na = st[na.r], nb = st[nb.r];
        return search_(k - v, m + 1, j);
    }

    int search(int a, int b, int k)
    {
        na = st[rt[a]], nb = st[rt[b]];
        return search_(k, 0, n - 1);
    }
};

int N, Q, k, i, c;
vector<int> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;

    A.resize(N); set<int> s;
    rep(i, N) { cin >> A[i]; s.insert(A[i]); }

    map<int, int> m; int id = 0;
    for (int x : s) m[x] = id++;

    rep(i, N) A[i] = m[A[i]];

    vector<vector<int>> O(id);
    rep(i, N) O[A[i]].push_back(i);

    PST<Node> pst(id);

    rep(i, N)
    {
        Node n = pst.query(i, A[i], A[i]), nn = Node(n.v + 1);
        pst.update(i, A[i], nn);
    }

    while (Q--)
    {
        cin >> k >> i >> c;

        int x =  pst.search(0, i + 1, k);

        if (O[x].size() >= c) cout << O[x][c - 1] << '\n';
        else cout << -1 << '\n';
    }
}