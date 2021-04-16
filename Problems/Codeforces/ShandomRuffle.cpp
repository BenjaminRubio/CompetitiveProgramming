#include <bits/stdc++.h>
using namespace std;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef pair<int, int> ii;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Node
{
    int p, sz = 0, v, acc, l = -1, r = -1, lzv = 0;
    bool lz = false, f = false;
    Node() : p(gen()), v(0), acc(0) {}
    Node(int x): p(gen()), sz(1), v(x), acc(x) {}
    void recalc(const Node &a, const Node &b)
    {
        sz = a.sz + b.sz + 1;
        acc = v + a.acc + b.acc;
    }
};

template <class node>
struct Treap
{
    vector<node> t; int n, r = -1;

    node get(int u) { return u != -1 ? t[u] : node(); }
    void recalc(int u) { t[u].recalc(get(t[u].l), get(t[u].r)); }
    int merge(int l, int r)
    {
        if (min(l, r) == -1) return l != -1 ? l : r;
        int ans = (t[l].p < t[r].p) ? l : r;
        if (ans == l) t[l].r = merge(t[l].r, r), recalc(l);
        if (ans == r) t[r].l = merge(l, t[r].l), recalc(r);
        return ans;
    }
    ii split(int u, int id)
    {
        if (u == -1) return {-1, -1};
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
    void print(int u)
    {
        if (u == -1) return;
        print(t[u].l);
        cout << t[u].v << ' ';
        print(t[u].r);
    }

    Treap(vector<int> &v) : n(v.size())
    { rep(i, n) t.emplace_back(v[i]), r = merge(r, i); }
};

int N, a, b, l, cl, cr, r;

int main()
{
    cin >> N;

    vector<int> v(N);
    rep(i, N) v[i] = i + 1;

    Treap<Node> treap(v);
    r = treap.r;

    rep(_, N)
    {
        cin >> a >> b; a--, b--;
        if (a >= b) continue;

        int s = min(b - a, N - b);
        tie(l, cl) = treap.split(r, a);
        tie(cl, cr) = treap.split(cl, s);
        if (b - a == s)
        {
            tie(cr, r) = treap.split(cr, s);
            r = treap.merge(treap.merge(l, cr), treap.merge(cl, r));
        }
        else
        {
            tie(cr, r) = treap.split(cr, b - a - s);
            r = treap.merge(treap.merge(l, r), treap.merge(cr, cl));
        }
    }

    treap.print(r);
    cout << '\n';
}
