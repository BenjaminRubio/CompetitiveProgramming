#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    int sz = 0, m0l = 0, m0r = 0 , m1l = 0, m1r = 0, m = 0;
    bool lz = false;
    Node() {}
    Node(int x) : sz(1), m(1)
    {
        m0l = m0r = (x == 0);
        m1l = m1r = (x == 1);
    }
    Node(const Node &a, const Node &b)
    {
        sz = a.sz + b.sz;
        m = max({a.m, b.m, a.m0r + b.m0l, a.m1r + b.m1l});
        m0l = a.m0l, m1l = a.m1l, m0r = b.m0r, m1r = b.m1r;
        if (a.m0l == a.sz) m0l = a.sz + b.m0l;
        if (a.m1l == a.sz) m1l = a.sz + b.m1l;
        if (b.m0r == b.sz) m0r = b.sz + a.m0r;
        if (b.m1r == b.sz) m1r = b.sz + a.m1r;
    }
    Node(const Node &b)
    {
        sz = b.sz; m = b.m;
        m0l = b.m1l, m1l = b.m0l;
        m0r = b.m1r, m1r = b.m0r;
    }
};

// 0 - indexed / inclusive - exclusive
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
    void push(int u, int i, int j)
    {
        st[u] = node(st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz ^= 1;
        st[u * 2 + 2].lz ^= 1;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, int u, int i, int j)
    {
        if (st[u].lz) push(u, i, j);
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j); return; }
        update(a, b, l, i, m); update(a, b, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b) { update(a, b, 0, 0, n - 1); }
};

int N, Q, t, l, r; char c;
vector<Node> v;

int main()
{
    cin >> N >> Q;

    v.resize(N);
    rep(i, N) { cin >> c; v[i] = Node(c - '0'); }

    STL<Node> stl(v, N);

    while (Q--)
    {
        cin >> t >> l >> r; l--, r--;
        stl.update(l, r);
        cout << stl.query(0, N - 1).m << '\n';
    }
}