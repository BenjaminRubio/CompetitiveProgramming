#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template <class node>
struct ST {};  // NEEDS INIT WITH NULLS

template <class node>
class HLD
{
    ST<node> st;
    vector<int> P, H, D, R, P;

    int dfs(vector<vector<int>> &G, int v)
    {
        int ans = 1, M = 0, s;
        for (int u : G[v]) if (u != P[v])
        {
            P[u] = v, D[u] = D[v] + 1;
            s = dfs(G, u), ans += s;
            if (s > M) H[v] = u, M = s;
        }
        return ans;
    }

    template <class OP>
    void process(int u, int v, OP op)
    {
        for (; R[u] != R[v]; v = P[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v);
            op(P[R[v]], P[v] + 1);
        }
        if (D[u] > D[v]) swap(u, v);
        op(P[u], P[v] + 1);             // VALUES ON VERTEX
        // op(P[u] + 1, P[v] + 1);      // VALUES ON EDGE
    }

public:
    HLD(vector<vector<int>> &G) : n(G.size()) P(n), st(n), D(n), R(n), P(n)
    {
        H.assign(n, -1); P[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (P[i] == -1 || H[P[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }

    void set(int v, const node &x) { st.set_point(P[v], x); } // VALUES ON VERTEX
    // void set(int u, int v, const node &x)                  // VALUES ON EDGE
    // {
    //     if (D[u] > D[v]) swap(u, v);
    //     st.set_point(P[v], x);
    // }
    void update(int u, int v, const node &x)
    { process(u, v, [this, &x](int l, int r) { st.update(l, r, x); }); }
    node query(int u, int v)
    {
        node ans = node();
        process(u, v, [this, &ans](int l, int r)
        { ans = node(ans, st.query(l, r)); });
        return ans;
    }
};