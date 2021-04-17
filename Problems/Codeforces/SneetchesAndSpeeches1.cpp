#include <bits/stdc++.h>
using namespace std;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef pair<int, int> ii;
#define ff first
#define ss second

struct Node
{
    int p, sz = 0, v, m0l = 0, m0r = 0 , m1l = 0, m1r = 0, m = 0, l = -1, r = -1;
    bool lz = false, f = false;
    Node() {}
    Node(int x): p(gen()), sz(1), v(x), m(1)
    {
        m0l = m0r = (x == 0);
        m1l = m1r = (x == 1);
    }
    void recalc(const Node &a, const Node &b)
    {
        sz = a.sz + b.sz + 1; m = max(a.m, b.m);
        m0l = a.m0l, m1l = a.m1l, m0r = b.m0r, m1r = b.m1r;
        if (v == 0) m = max(m, a.m0r + 1 + b.m0l);
        if (v == 1) m = max(m, a.m1r + 1 + b.m1l);
        if (a.m0r == a.sz && v == 0) m0l = a.sz + 1 + b.m0l;
        if (a.m1r == a.sz && v == 1) m1l = a.sz + 1 + b.m1l;
        if (b.m0l == b.sz && v == 0) m0r = b.sz + 1 + a.m0r;
        if (b.m1l == b.sz && v == 1) m1r = b.sz + 1 + a.m1r;
    }
    void upd_lazy() { lz ^= 1; }
    void lazy() { v ^= 1, swap(m0l, m1l), swap(m0r, m1r), lz = 0; }
};

template <class node>
struct Treap
{
    vector<node> t; int n, r = -1;

    node get(int u) { return u != -1 ? t[u] : node(); }
    void recalc(int u)
    {
        int l = t[u].l, r = t[u].r;
        push(l); push(r);
        t[u].recalc(get(l), get(r));
    }
    void push(int u)
    {
        if (u == -1 || !t[u].lz) return;
        int l = t[u].l, r = t[u].r;
        if (l != -1) t[l].upd_lazy();
        if (r != -1) t[r].upd_lazy();
        t[u].lazy();
    }
    int merge(int l, int r)
    {
        if (min(l, r) == -1) return l != -1 ? l : r;
        push(l); push(r);
        int ans = (t[l].p < t[r].p) ? l : r;
        if (ans == l) t[l].r = merge(t[l].r, r), recalc(l);
        if (ans == r) t[r].l = merge(l, t[r].l), recalc(r);
        return ans;
    }
    ii split(int u, int id)
    {
        if (u == -1) return {-1, -1};
        push(u);
        if (get(t[u].l).sz >= id)
        {
            ii ans = split(t[u].l, id);
            t[u].l = ans.ss; recalc(u);
            return {ans.ff, u};
        }
        id -= get(t[u].l).sz + 1;
        ii ans = split(t[u].r, id);
        t[u].r = ans.ff; recalc(u);
        return {u, ans.ss};
    }
    int update(int u, int l, int r)
    {
        if (l > r) return u;
        ii a = split(u, l), b = split(a.ss, r - l + 1);
        t[b.ff].upd_lazy();
        return merge(a.ff, merge(b.ff, b.ss));
    }

    Treap(vector<int> &v) : n(v.size())
    { rep(i, n) t.emplace_back(v[i]), r = merge(r, i); }
};

int N, Q, t, l, r; char c;
vector<int> v;

int main()
{
    cin >> N >> Q;

    v.resize(N);
    rep(i, N) { cin >> c; v[i] = c - '0'; }

    Treap<Node> treap(v);
    int root = treap.r;

    while (Q--)
    {
        cin >> t >> l >> r; l--, r--;
        root = treap.update(root, l, r);
        cout << treap.t[root].m << '\n';
    }
}