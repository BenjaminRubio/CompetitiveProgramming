#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int S;

struct Query
{
    int l, r, id, t;
    Query(int l, int r, int id, int t) : l(l), r(r), id(id), t(t) {}
    bool operator<(Query &q)
    {
        return l / S < q.l / S or (l / S == q.l / S and r < q.r);
    }
};

const int MAXN = 1e5;

int N, Q, u, v, id, s;
vector<vector<int>> G;
int A[2 * MAXN], I[2 * MAXN], W[MAXN], L[MAXN], R[MAXN], C[MAXN], O[MAXN];

struct LCA
{
    vector<int> A, D; int n, maxe;

    int& anc(int u, int e) { return A[e * n + u]; }    
    int inline log2(int x) { return 31 - __builtin_clz(x); }
    
    void dfs(int u, int p, int depth)
    {
        anc(u, 0) = p; D[u] = depth;
        for (int v : G[u]) if (v != p) dfs(v, u, depth + 1);
    }
    LCA(int root)
    {
        n = N, maxe = log2(n);
        D.assign(n, -1); A.resize(n * (maxe + 1));
        dfs(root, -1, 0);
        repx(e, 1, maxe + 1) rep(u, n)
        {
            int a = anc(u, e - 1);
            anc(u, e) = (a == -1 ? -1 : anc(a, e - 1));
        }
    }
    int raise(int u, int k)
    {
        for (int e = 0; k; e++, k >>= 1) if (k & 1) u = anc(u, e);
        return u;
    }
    int lca(int u, int v)
    {       
        if (D[u] < D[v]) swap(u, v); 
        u = raise(u, D[u] - D[v]);
        if (u == v) return u;
        rep_(e, maxe) if (anc(u,e) != anc(v,e))
            u = anc(u,e), v = anc(v,e);
        return anc(u,0);
    }
};

void dfs(int u, int p)
{
    A[id] = W[u], I[id] = u, L[u] = id++;
    for (int v : G[u]) if (v != p) dfs(v, u);
    A[id] = W[u], I[id] = u, R[u] = id++;
}

void update(int p)
{
    if (O[I[p]]) C[A[p]]++, s += (C[A[p]] == 1);
    else s -= (C[A[p]] == 1), C[A[p]]--;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q; S = sqrt(N);

    set<int> ss;
    rep(i, N) { cin >> W[i]; ss.insert(W[i]); }

    map<int, int> m; id = 0;
    for (int x : ss) m[x] = id++;

    rep(i, N) W[i] = m[W[i]];

    G.assign(N, {});
    rep(i, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    id = 0; dfs(0, -1); LCA lca(0);

    vector<Query> q;
    rep(i, Q)
    {
        cin >> u >> v; u--, v--;
        int l = lca.lca(u, v);
        if (l == u) q.emplace_back(L[u], L[v], i, -1);
        else if (l == v) q.emplace_back(L[v], L[u], i, -1);
        else if (R[u] < L[v]) q.emplace_back(R[u], L[v], i, L[l]);
        else if (R[v] < L[u]) q.emplace_back(R[v], L[u], i, L[l]);
    }

    sort(q.begin(), q.end());

    int l = 0, r = 0; s = 1, O[0] = 1, C[A[0]] = 1;
    vector<int> ans(Q);
    for (Query &e : q)
    {
        while (e.r > r) r++, O[I[r]] ^= 1, update(r);
        while (e.r < r) O[I[r]] ^= 1, update(r), r--;
        while (e.l > l) O[I[l]] ^= 1, update(l), l++;
        while (e.l < l) l--, O[I[l]] ^= 1, update(l);

        ans[e.id] = s;
        if (e.t != -1 && C[A[e.t]] == 0) ans[e.id]++;
    }

    rep(i, Q) cout << ans[i] << '\n';
}