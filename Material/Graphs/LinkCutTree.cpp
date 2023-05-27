#include "../Template.cpp"

// Basic LCT for Dynamic DSU

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


// Basic LCT for dynamic lca (no rerooting)

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


// Complete LCT

struct Node
{
    int c[2] = {0, 0}, p = 0, f = 0;
    ll v = 0, pth = 0, sub = 0, vir = 0;
};

template <class node>
struct LinkCut
{
    vector<node> T;

    LinkCut(int n) : T(n + 1) {}
    void push(int x)
    {
        if (!x || !T[x].f) return;
        int l = T[x].c[0], r = T[x].c[1];
        T[l].f ^= 1, T[r].f ^= 1, T[x].f = 0;
        swap(T[x].c[0], T[x].c[1]);
    }
    void pull(int x)
    {
        int l = T[x].c[0], r = T[x].c[1];
        push(l); push(r);
        T[x].pth = T[l].pth + T[x].v + T[r].pth;
        T[x].sub = T[x].vir + T[l].sub + T[r].sub + T[x].v;
    }
    void set(int x, int d, int y) { T[x].c[d] = y, T[y].p = x; pull(x); }
    int dir(int x)
    {
        int p = T[x].p; if (!p) return -1;
        return T[p].ch[0] == x ? 0 : T[p].ch[1] == x ? 1 : -1;
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
    int mark(int x)
    {
        int u = x, v = 0;
        for (; u; v = u, u = T[u].p)
        {
            splay(u);
            int &w = T[u].c[1];
            T[u].vir += T[w].sub - T[v].sub;
            w = v; pull(u);
        }
        return splay(x), v;
    }
    void root(int x) { mark(x); T[x].f ^= 1; push(x); }
    void update(int u, ll v) { mark(u); T[u].v = v; pull(u); }
    void link(int u, int v)
    {
        root(u); mark(v);
        T[v].vir += T[u].sub, T[u].p = v;
        pull(v);
    }
    void cut(int u, int v)
    {
        root(u); mark(v);
        T[v].c[0] = T[u].p = 0;
        pull(v);
    }
    int lca(int u, int v)
    {
        if (u == v) return u;
        mark(u); int r = mark(v);
        return T[u].p ? r : 0;
    }
    ll subtree(int u, int v)
    {
        root(v); mark(u);
        return T[u].vir + T[u].v;
    }
    ll path(int u, int v)
    {
        root(u); mark(v);
        return T[v].pth;
    }
};
