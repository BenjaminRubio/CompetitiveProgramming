#include <bits/stdc++.h>
using namespace std;

struct LCT
{
    struct node { int c[2] = {0, 0}, p = 0, f = 0; };
    vector<node> T;

    LCT(int n) : T(n + 1) {}
    void set(int x, int d, int y) { T[x].c[d] = y, T[y].p = x; }
    int dir(int x)
    {
        int p = T[x].p; if (!p) return -1;
        return T[p].c[0] == x ? 0 : T[p].c[1] == x ? 1 : -1;
    }
    void rotate(int x)
    {
        int y = T[x].p, z = T[y].p, dx = dir(x), dy = dir(y);
        set(y, dx, T[x].c[!dx]), set(x, !dx, y);
        if (~dy) set(z, dy, x);
        T[x].p = z;
    }
    void splay(int x)
    {
        for (;~dir(x);)
        {
            int y = T[x].p, z = T[y].p;
            int dx = dir(x), dy = dir(y);
            if (~dy) rotate(dx != dy ? x : y);
            rotate(x);
        }
    }
    int mark(int x)
    {
        int u = x, v = 0;
        for (; u; v = u, u = T[u].p)
            splay(u), T[u].c[1] = v;
        splay(x); return v;
    }
    void link(int u, int v) { mark(u); mark(v); T[u].p = v; }
    void cut(int u) { mark(u); T[u].c[0] = T[T[u].c[0]].p = 0; }
    int lca(int u, int v)
    {
        if (u == v) return u;
        mark(u); int r = mark(v);
        return r;
    }
};

int N, M, u, v;
string s;

int main()
{
    while (cin >> N >> M)
    {
        LCT lct(N);
        while (M--)
        {
            cin >> s >> u;
            if (s == "link") { cin >> v; lct.link(u, v); }
            if (s == "cut") lct.cut(u);
            if (s == "lca") { cin >> v; cout << lct.lca(u, v) << '\n'; }
        }
    }
}
