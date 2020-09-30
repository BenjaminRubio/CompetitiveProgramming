#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M;
vector<pair<int, int>> R, S;

struct Node
{
    int v = 0, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(max(a.v, b.v)) {}
    Node(int x, const Node &b) { v = max(b.v, x); }
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
        st[u] = node(x, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv = max(st[u * 2 + 1].lzv, x);
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv = max(st[u * 2 + 2].lzv, x);
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
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m);
        update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(vector<node> &v, int N) : st(N * 4 + 5) { n = N; build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};

int main()
{
    cin >> N >> M;

    R.resize(N);
    rep(i, N) cin >> R[i].ff >> R[i].ss;

    S.resize(M);
    rep(i, M) cin >> S[i].ff >> S[i].ss;

    vector<Node> v(1001000);
    STL<Node> stl(v, 1001000);

    rep(i, N) rep(j, M) if (R[i].ff <= S[j].ff)
        stl.update(0, S[j].ff - R[i].ff, S[j].ss + 1 - R[i].ss);

    int ans = INT_MAX;
    rep(i, 1000100) ans = min(ans, i + stl.query(i, i).v);

    cout << ans << '\n';
}