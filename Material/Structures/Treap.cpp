#include <bits/stdc++.h>
using namespace std;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef pair<int, int> ii;
#define ff first
#define ss second

struct Node
{
    int p, sz = 0, v, acc, l = -1, r = -1, lzv = 0;
    bool lz = false, f = false;
    Node() : v(0), acc(0) {}
    Node(int x): p(gen()), sz(1), v(x), acc(x) {}
    void recalc(const Node &a, const Node &b)
    {
        sz = a.sz + b.sz + 1;
        acc = v + a.acc + b.acc;
    }
    void upd_lazy(int x) { lz = 1, lzv += x; }
    void lazy() { v += lzv, acc += sz * lzv, lz = 0, lzv = 0; }
};

template <class node>
struct Treap
{
    vector<node> t; int n, r = -1;

    node get(int u) { return u != -1 ? t[u] : node(); }
    void recalc(int u) { t[u].recalc(get(t[u].l), get(t[u].r)); }
    void push(int u)
    {
        if (u == -1 || !t[u].lz) return;
        int l = t[u].l, r = t[u].r;
        if (l != -1) t[l].upd_lazy(t[u].lzv);
        if (r != -1) t[r].upd_lazy(t[u].lzv);
        t[u].lazy();
    }
    void flip(int u)
    {
        if (u == -1 || !t[u].f) return;
        int l = t[u].l, r = t[u].r;
        if (l != -1) t[l].f ^= 1;
        if (r != -1) t[r].f ^= 1;
        swap(t[u].l, t[u].r); t[u].f = 0;
        recalc(u);
    }
    int merge(int l, int r)
    {
        if (l == -1 || r == -1) return l != -1 ? l : r;
        push(l); push(r); flip(l); flip(r);
        int ans = (t[l].p < t[r].p) ? l : r;
        if (ans == l) t[l].r = merge(t[l].r, r), recalc(l);
        if (ans == r) t[r].l = merge(l, t[r].l), recalc(r);
        return ans;
    }
    ii split(int u, int id)
    {
        if (u == -1) return {-1, -1};
        push(u); flip(u);
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
    int update(int u, int l, int r, int v)
    {
        ii a = split(u, l), b = split(a.ss, r - l + 1);
        t[b.ff].upd_lazy(v);
        return merge(a.ff, merge(b.ff, b.ss));
    }
    void print(int u)
    {
        if (u == -1) return;
        push(u); flip(u);
        print(t[u].l);
        cout << t[u].v << ' ';
        print(t[u].r);
    }

    Treap(vector<int> &v) : n(v.size())
    { for (int i = 0; i < n; i++) t.emplace_back(v[i]), r = merge(r, i); }
};