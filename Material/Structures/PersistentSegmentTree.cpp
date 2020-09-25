#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int v, l, r;
    Node() : v(0), l(0), r(0) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    { v = a.v + b.v; }
};

// 0 - indexed / inclusive - inclusive
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
        st[x] = node(st[l], st[r], l, r); return x;
    }
    int build(vector<node> &arr, int i, int j)
    {
        int u = cnt++, m = (i + j) / 2;
        if (i == j) { st[u] = arr[i]; return u; }
        int l = st[u].l = build(arr, i, m);
        int r = st[u].r = build(arr, m + 1, j);
        st[u] = node(st[l], st[r], l, r); return u;
    }

    PST(vector<node> &arr) : st(1e7), rt(1e5)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};

// Init with null's (no build) (requires l = r = 0 as default)
template <class node>
struct PST
{
    int cnt = 1, n, rc = 1;
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

    PST(int N) : st(1e7), rt(1e5), n(N) {}
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};