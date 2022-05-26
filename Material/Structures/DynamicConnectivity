#include "../Template.cpp"
#include "DSU.cpp"

// 0 indexed - inclusive/exclusive
struct DC
{
    int n; DSU D; vvp t;
    DC(int N) : n(N), D(N), t(2 * N) {}
    void upd(int l, int r, pii p) // add edge p to all times in interval [l, r]
    {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) t[l++].pb(p);
            if (r & 1) t[--r].pb(p);
        }
    }
    void process(int u)  // To process all, call process(1)
    {
        for (auto &e : t[u]) D.unite(e.ff, e.ss);
        if (u >= n)
        {
            // do stuff with D at time u - n
        }
        else process(2 * u), process(2 * u + 1);
        for (auto &e : t[u]) D.rollback();
    }
};