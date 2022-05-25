#include "../Template.cpp"

struct Node
{
    int v, l = 0, r = 0, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b, int l, int r) : v(a.v + b.v), l(l), r(r) {}
    Node(int x, int i, int j, const Node &b) : l(b.l), r(b.r)
    { v = b.v + (j - i + 1) * x; }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct PSTL
{
    int cnt = 0, n, rc = 0;
    vector<node> st; vi rt;

    void push(int u, int v, int i, int j)
    {
        st[u] = node(v, i, j, st[u]);
        if (i == j) return;
        st[cnt] = st[st[u].l]; int l = cnt++;
        st[cnt] = st[st[u].r]; int r = cnt++;
        st[u].l = l, st[l].lz = 1, st[l].lzv += v;
        st[u].r = r, st[r].lz = 1, st[r].lzv += v;
    }
    node query(int u, int a, int b, int i, int j)
    {
        if (j < a || b < i) return node();
        if (st[u].lz) push(u, st[u].lzv, i, j);
        if (a <= i && j <= b) return st[u];
        int m = (i + j) / 2, l = st[u].l, r = st[u].r;
        return node(query(l, a, b, i, m), query(r, a, b, m + 1, j), l, r);
    }
    int update(int u, int a, int b, int v, int i, int j)
    {
        if (st[u].lz) push(u, st[u].lzv, i, j);
        if (j < a || b < i) return u;
        st[cnt] = st[u]; int x = cnt++, m = (i + j) / 2;
        if (a <= i && j <= b) { push(x, v, i, j); return x; }
        int l = st[x].l = update(st[x].l, a, b, v, i, m);
        int r = st[x].r = update(st[x].r, a, b, v, m + 1, j);
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

    PSTL(vector<node> &arr) : st(1e7), rt(1e5)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    void update(int t, int a, int b, int v)
    { rt[rc++] = update(rt[t], a, b, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};

// Direct accumulate (No Push) Faster and shorter
struct Node
{
    int v = 0, l = 0, r = 0, lzv = 0;
    bool lz = false;
    Node() {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b, int l, int r) : v(a.v + b.v), l(l), r(r) {}
    Node(int x, int i, int j, const Node &b)
    { *this = b; v += (j - i + 1) * x; } // *this = b needed in this variant (keeps lazy)
};

template <class node>
struct PSTL
{
    int cnt = 0, n, rc = 0;
    vector<node> st; vi rt;
    
    node query(int u, int a, int b, int i, int j, ll acc)
    {
        if (j < a || b < i) return node();
        if (st[u].lz) acc += st[u].lzv;
        int m = (i + j) / 2, l = st[u].l, r = st[u].r;
        if (a <= i && j <= b) return node(acc, i, j, st[u]);
        return node(query(l, a, b, i, m, acc), query(r, a, b, m + 1, j, acc), l, r);
    }
    int update(int u, int a, int b, int v, int i, int j)
    {
        if (j < a || b < i) return u;
        st[cnt] = st[u]; int x = cnt++, m = (i + j) / 2;
        if (a <= i && j <= b) { st[x].lz = 1, st[x].lzv += v; return x; }
        int l = st[x].l = update(st[x].l, a, b, v, i, m);
        int r = st[x].r = update(st[x].r, a, b, v, m + 1, j);
        st[x] = node(v, max(i, a), min(j, b), st[x]); return x;
    }
    int build(vector<node> &arr, int i, int j)
    {
        int u = cnt++, m = (i + j) / 2;
        if (i == j) { st[u] = arr[i]; return u; }
        int l = st[u].l = build(arr, i, m);
        int r = st[u].r = build(arr, m + 1, j);
        st[u] = node(st[l], st[r], l, r); return u;
    }

    PSTL(vector<node> &arr) : st(5e6), rt(2e5)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    int update(int t, int a, int b, int v)
    { rt[rc] = update(rt[t], a, b, v, 0, n - 1); return rc++; }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1, 0); }
};
