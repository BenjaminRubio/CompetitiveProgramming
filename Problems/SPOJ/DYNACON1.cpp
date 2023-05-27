#include <bits/stdc++.h>
using namespace std;

struct LCT
{
    struct node { int c[2] = {0, 0}, p = 0, f = 0; };
    vector<node> T;

    LCT(int n) : T(n + 1) {}
    void push(int x)
    {
        if (!x || !T[x].f) return;
        int l = T[x].c[0], r = T[x].c[1];
        T[l].f ^= 1, T[r].f ^= 1, T[x].f = 0;
        swap(T[x].c[0], T[x].c[1]);
    }
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
        for (push(x); ~dir(x);)
        {
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(x), dy = dir(y);
            if (~dy) rotate(dx != dy ? x : y);
            rotate(x);
        }
    }
    void mark(int x)
    {
        for (int u = x, v = 0; u; v = u, u = T[u].p)
            splay(u), T[u].c[1] = v;
        splay(x);
    }
    void root(int x) { mark(x); T[x].f ^= 1; push(x); }
    void link(int u, int v) { root(u); mark(v); T[u].p = v; }
    void cut(int u, int v) { root(u); mark(v); T[v].c[0] = T[u].p = 0; }
    int get(int x)
    {
        mark(x); int a = x;
        while (T[a].c[0]) a = T[a].c[0];
        splay(a); return a;
    }
};

int N, M, u, v;
string s;

int main()
{
    cin >> N >> M;

    LCT lct(N);
    while (M--)
    {
        cin >> s >> u >> v;
        if (s == "add") lct.link(u, v);
        if (s == "rem") lct.cut(u, v);
        if (s == "conn") cout << (lct.get(u) == lct.get(v) ? "YES" : "NO") << '\n';
    }
}
