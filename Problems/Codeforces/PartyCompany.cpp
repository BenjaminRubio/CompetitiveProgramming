#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    int v, a, lzv = 0;
    bool lz = false;
    Node() : v(0), a(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(a.v + b.v), a(a.a + b.a) {}
    Node(int x, int i, int j, const Node &b)
    {
        v = b.v + b.a * x; a = b.a;
    }
};

template <class node>
struct STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push(int u, int i, int j, int x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv += x;
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv += x;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, int v, int u, int i, int j)
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }
    void activate(int a, int u, int i, int j) {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a or a < i) return;
        if (i == j) { st[u].a = 1; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        activate(a, l, i, m); activate(a, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
    void activate(int a) { activate(a, 0, 0, n - 1); }
};

int N, M, a, id = 0, o, l, r;
vector<int> A, L, R;
vector<vector<int>> G;

#define MAXN 100010
#define MAXLOG 18
#define ff first
#define ss second
int h[MAXN];
int anc[MAXN][MAXLOG]; //ancestor[V][ceil(log2(V))] inicializado en -1

void dfs(int u)
{
    L[u] = id++;
    for (int v : G[u]) dfs(v);
    R[u] = id;
}

void dfs_preprocess(int u, int p = -1)
{
    anc[u][0] = p;
    if (p != -1)  h[u] = h[p] + 1;
    for (int i = 1; i < MAXLOG; ++i) if (~anc[u][i - 1])
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (auto v: G[u]) if (v != p) dfs_preprocess(v, u);
}

int last_anc(int v, int r)
{
    for (int i = MAXLOG - 1; i >= 0; i--) if (anc[v][i] != -1 && A[anc[v][i]] <= r)
        v = anc[v][i];
    return v;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    G.resize(N); A.resize(N);
    vector<pair<int, int>> E;
    rep(i, N)
    {
        cin >> A[i] >> a; a--;
        if (i) G[a].push_back(i);
        E.emplace_back(A[i], i);
    }

    memset(anc, -1, sizeof anc);
    memset(h, 0, sizeof h);
    dfs_preprocess(0);

    vector<pair<int, int>> S;
    rep(_, M)
    {
        cin >> o >> l >> r; o--;
        S.emplace_back(l, last_anc(o, r));
    }

    sort(S.rbegin(), S.rend());

    L.resize(N), R.resize(N);
    dfs(0);
    vector<Node> aa(N);
    STL<Node> stl(aa, N);

    sort(E.rbegin(), E.rend());

    int i = 0;
    for (auto &e : E)
    {
        while (i < M && S[i].ff > e.ff)
        { stl.update(L[S[i].ss], R[S[i].ss] - 1, 1); i++; }
        stl.activate(L[e.ss]);
    }
    while (i < M) { stl.update(L[S[i].ss], R[S[i].ss] - 1, 1); i++; }

    rep(i, N) cout << stl.query(L[i], L[i]).v << ' ';
    cout << '\n';
}