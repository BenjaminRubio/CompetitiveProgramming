
template <class ST, class node>
class HLD
{
    ST st;
    vi A, H, D, R, P;

    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }
    template <class OP>
    void path(int u, int v, OP op)
    {
        for (; R[u] != R[v]; v = A[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v);
            op(P[R[v]], P[v] + 1);
        }
        if (D[u] > D[v]) swap(u, v);
        op(P[u], P[v] + 1);                // VALUES ON VERTEX
        // op(P[u] + 1, P[v] + 1);         // VALUES ON EDGE
    }

public:
    HLD(vector<vi> &G, int n) : A(n), st(n), D(n), R(n), P(n)
    {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    void set(int v, const node &x) { st.set(P[v], x); } // VALUES ON VERTEX
    // void set(int u, int v, const node &x)            // VALUES ON EDGE
    // {
    //     if (D[u] > D[v]) swap(u, v);
    //     st.set(P[v], x);
    // }
    void update(int u, int v, const node& x)                  // OPTIONAL FOR RANGE UPDATES
    { path(u, v, [this, &x](int l, int r) { st.update(l, r, x); }); }
    node query(int u, int v)
    {
        node ans = node();
        path(u, v, [this, &ans](int l, int r) { ans = node(ans, st.query(l, r)); });
        return ans;
    }
};

// USAGE:  HLD<ST<Node>, Node> hld(G, N);

//// NON COMMUTATIVE QUERIES :

template <class ST, class node>
class HLD
{
    ST st;
    vi A, H, D, R, P;

    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }

public:
    node path(int u, int v)
    {
        node ans1, ans2; bool d = 0;
        for (; R[u] != R[v]; v = A[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v), d = !d;
            if (d) ans1 = node(st.query(P[R[v]], P[v] + 1), ans1);
            else ans2 = node(st.query(P[R[v]], P[v] + 1), ans2);
        }
        if (D[u] > D[v]) swap(u, v), d = !d;
        if (d) ans1 = node(st.query(P[u], P[v] + 1), ans1);
        else ans2 = node(st.query(P[u], P[v] + 1), ans2);
        ans1.sw(); return node(ans1, ans2);
    }
    HLD(vector<vi> &G, int n) : A(n), st(n), D(n), R(n), P(n)
    {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    void set(int v, const node &x) { st.set(P[v], x); }
};