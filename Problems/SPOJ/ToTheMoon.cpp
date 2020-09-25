#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    ll v = 0, l = 0, r = 0, lzv = 0;
    bool lz = false;
    Node() {}
    Node(ll x) : v(x) {}
    Node(const Node &a, const Node &b, int l, int r) : v(a.v + b.v), l(l), r(r) {}
    Node(ll x, ll i, ll j, const Node &b) : l(b.l), r(b.r)
    { v = b.v + (j - i + 1ll) * x; }
};

template <class node>
struct PSTL
{
    int cnt = 0, n, rc = 0;
    vector<node> st; vector<int> rt;

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

    PSTL(vector<node> &arr) : st(1e7), rt(2e5)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    int update(int t, int a, int b, int v)
    { rt[rc] = update(rt[t], a, b, v, 0, n - 1); return rc++; }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};

int N, Q, a, l, r, d; char t;
vector<Node> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;

    A.resize(N);
    rep(i, N) { cin >> a; A[i] = Node(a); }

    PSTL<Node> pstl(A);

    vector<int> T(200000, 0); int ct = 0;
    while (Q--)
    {
        cin >> t;
        if (t == 'C')
        {
            cin >> l >> r >> d; l--, r--;
            T[++ct] = pstl.update(T[ct], l, r, d);
        }
        if (t == 'Q')
        {
            cin >> l >> r; l--, r--;
            cout << pstl.query(T[ct], l, r).v << '\n';
        }
        if (t == 'H')
        {
            cin >> l >> r >> d; l--, r--;
            cout << pstl.query(T[d], l, r).v << '\n';
        }
        if (t == 'B') { cin >> d; ct = d; }
    }
}