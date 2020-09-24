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
    int cnt = 0, n, rc = 0;
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
        st[x] = node(st[st[x].l], st[st[x].r], l, r); return x;
    }
    int build(vector<node> &arr, int i, int j)
    {
        int u = cnt++, m = (i + j) / 2;
        if (i == j) { st[u] = arr[i]; return u; }
        int l = st[u].l = build(arr, i, m);
        int r = st[u].r = build(arr, m + 1, j);
        st[u] = node(st[st[u].l], st[st[u].r], l, r); return u;
    }

    PST(vector<node> &arr) : st(2e7), rt(1e5)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }

    int search(int a, int b, int k, int i, int j)
    {
        if (i == j) return i;
        int m = (i + j) / 2;
        int q1a = query(a, i, m).v, q1b = query(b + 1, i, m).v;
        if (q1b - q1a >= k) return search(a, b, k, i, m);
        else return search(a, b, k - q1b + q1a, m + 1, j);
    }
};

int N, Q, a, b, k;
vector<int> A;
map<int, int> m, m_;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    
    A.resize(N); set<int> s;
    rep(i, N) { cin >> A[i]; s.insert(A[i]); }

    int id = 0;
    for (int x : s) m[x] = id, m_[id++] = x;

    vector<Node> v(s.size());
    PST<Node> pst(v);

    rep(i, N)
    {
        Node p = pst.query(i, m[A[i]], m[A[i]]); p.v++;
        pst.update(i, m[A[i]], p);
    }

    rep(_, Q)
    {
        cin >> a >> b >> k; a--, b--;
        cout << m_[pst.search(a, b, k, 0, s.size() - 1)] << '\n';
    }
}