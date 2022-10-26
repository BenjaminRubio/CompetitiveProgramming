#include "../Template.cpp"

struct Node
{
    ll s, mx1, mx2, mxc, mn1, mn2, mnc, lz = 0;
    Node() : s(0), mx1(LLONG_MIN), mx2(LLONG_MIN), mxc(0), mn1(LLONG_MAX), mn2(LLONG_MAX), mnc(0) {}
    Node(ll x) : s(x), mx1(x), mx2(LLONG_MIN), mxc(1), mn1(x), mn2(LLONG_MAX), mnc(1) {}
    Node(const Node &a, const Node &b)
    {
        // add
        s = a.s + b.s;
        // max
        if (a.mx1 > b.mx1) mx1 = a.mx1, mxc = a.mxc, mx2 = max(b.mx1, a.mx2);
        if (a.mx1 < b.mx1) mx1 = b.mx1, mxc = b.mxc, mx2 = max(a.mx1, b.mx2);
        if (a.mx1 == b.mx1) mx1 = a.mx1, mxc = a.mxc + b.mxc, mx2 = max(a.mx2, b.mx2);
        // min
        if (a.mn1 < b.mn1) mn1 = a.mn1, mnc = a.mnc, mn2 = min(b.mn1, a.mn2);
        if (a.mn1 > b.mn1) mn1 = b.mn1, mnc = b.mnc, mn2 = min(a.mn1, b.mn2);
        if (a.mn1 == b.mn1) mn1 = a.mn1, mnc = a.mnc + b.mnc, mn2 = min(a.mn2, b.mn2);
    }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct STB
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push_add(int u, int i, int j, ll v)
    {
        st[u].s += (j - i + 1) * v;
        st[u].mx1 += v, st[u].mn1 += v, st[u].lz += v;
        if (st[u].mx2 != LLONG_MIN) st[u].mx2 += v;
        if (st[u].mn2 != LLONG_MAX) st[u].mn2 += v;
    }
    void push_max(int u, ll v, bool l) // for min op
    {
        if (v >= st[u].mx1) return;
        st[u].s -= st[u].mx1 * st[u].mxc;
        st[u].mx1 = v;
        st[u].s += st[u].mx1 * st[u].mxc;
        if (l) st[u].mn1 = st[u].mx1;
        else if (v <= st[u].mn1) st[u].mn1 = v;
        else if (v < st[u].mn2) st[u].mn2 = v;
    }
    void push_min(int u, ll v, bool l) // for max op
    {
        if (v <= st[u].mn1) return;
        st[u].s -= st[u].mn1 * st[u].mnc;
        st[u].mn1 = v;
        st[u].s += st[u].mn1 * st[u].mnc;
        if (l) st[u].mx1 = st[u].mn1;
        else if (v >= st[u].mx1) st[u].mx1 = v;
        else if (v > st[u].mx2) st[u].mx2 = v;
    }
    void push(int u, int i, int j)
    {
        if (i == j) return;
        // add
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        push_add(l, i, m, st[u].lz);
        push_add(r, m + 1, j, st[u].lz);
        st[u].lz = 0;
        // max
        push_max(l, st[u].mx1, i == m);
        push_max(r, st[u].mx1, m + 1 == j);
        // min
        push_min(l, st[u].mn1, i == m);
        push_min(r, st[u].mn1, m + 1 == r);
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (b < i || j < a) return node();
        if (a <= i && j <= b) return st[u];
        push(u, i, j);
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update_add(int a, int b, ll v, int u, int i, int j)
    {
        if (b < i || j < a) return;
        if (a <= i && j <= b) { push_add(u, i, j, v); return; }
        push(u, i, j);
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        update_add(a, b, v, l, i, m); update_add(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }
    void update_min(int a, int b, ll v, int u, int i, int j)
    {
        if (b < i || j < a || v >= st[u].mx1) return;
        if (a <= i && j <= b && v > st[u].mx2) { push_max(u, v, i == j); return; }
        push(u, i, j);
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        update_min(a, b, v, l, i, m); update_min(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }
    void update_max(int a, int b, ll v, int u, int i, int j)
    {
        if (b < i || j < a || v <= st[u].mn1) return;
        if (a <= i && j <= b && v < st[u].mn2) { push_min(u, v, i == j); return; }
        push(u, i, j);
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        update_max(a, b, v, l, i, m); update_max(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STB(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update_add(int a, int b, ll v) { update_add(a, b, v, 0, 0, n - 1); }
    void update_min(int a, int b, ll v) { update_min(a, b, v, 0, 0, n - 1); }
    void update_max(int a, int b, ll v) { update_max(a, b, v, 0, 0, n - 1); }
};
