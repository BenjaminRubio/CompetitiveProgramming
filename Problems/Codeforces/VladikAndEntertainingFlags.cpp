#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template <class node>
class ST
{
    vector<node> t;
    int n, N;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
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

int N, M, Q, l, r;
vector<vector<int>> m;

struct Node
{
    int c, l, r;
    vector<int> cl, cr, al, ar;
    Node() : c(0) {}
    Node(int id) : c(N), l(id), r(id), cl(N), cr(N), al(N), ar(N)
    {
        rep(i, N) cl[i] = cr[i] = id * N + i;
        rep(i, N) if (i and m[i][id] == m[i - 1][id]) merge(cl[i - 1], cr[i]);
    }
    Node(const Node &a, const Node &b) : c(0)
    {
        if (!a.c) { c = b.c; l = b.l; r = b.r; cl = b.cl; cr = b.cr; return; }
        if (!b.c) { c = a.c; l = a.l; r = a.r; cl = a.cl; cr = a.cr; return; }
        c = a.c + b.c; l = a.l, r = b.r;
        cl = a.cl; cr = b.cr; al = a.cr; ar = b.cl;
        rep(i, N) if (m[i][a.r] == m[i][b.l]) merge(al[i], ar[i]);
    }
    void merge(int x, int y)
    {
        if (x == y) return;
        if (x > y) swap(x, y);
        rep(i, N) if (cl[i] == x) cl[i] = y;
        rep(i, N) if (cr[i] == x) cr[i] = y;
        rep(i, N) if (al[i] == x) al[i] = y;
        rep(i, N) if (ar[i] == x) ar[i] = y;
        c--;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> Q;

    m.assign(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> m[i][j];

    vector<Node> v;
    rep(i, M) v.emplace_back(i);
    ST<Node> st(v);

    rep(_, Q)
    {
        cin >> l >> r;
        cout << st.query(l - 1, r).c << '\n';
    }
}