#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<float> vfloat;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

// Apuntes Pablo Messina.

int n, m, a, b;
graph g, g_inv;
vi v;

int inv_dfs(int root, int size)
{
    stack<int> s;
    vector<bool> visited;
    visited.assign(size, false);
    int count = 0;

    s.push(root);
    visited[root] = true;
    count++;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (int v : g_inv[u])
        {
            if (!visited[v])
            {
                visited[u] = true;
                count++;
                s.push(v);
            }
        }
    }
    return count;
}

struct tarjanSCC
{
    vector<int> _stack, ids, low;
    vector<bool> instack;
    vector<vector<int>> *g;
    int n, ID;
    void dfs(int u)
    {
        ids[u] = low[u] = ID++;
        instack[u] = true;
        _stack.push_back(u);
        for (int v : (*g)[u])
        {
            if (ids[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (instack[v])
            {
                low[u] = min(low[v], low[u]);
            }
        }
        if (low[u] == ids[u])
        {
            vi partial_v;
            par first = {0, false};
            while (1)
            {
                int x = _stack.back();
                _stack.pop_back();
                instack[x] = false;
                partial_v.pb(x);
                if (!first.second)
                {
                    first.second = true;
                    first.first = x;
                }
                if (x == u)
                    break;
            }

            if (inv_dfs(first.first, n) >= n)
                for (auto a : partial_v)
                    v.pb(a);
        }
    }
    tarjanSCC(vector<vector<int>> &_g)
    {
        g = &_g;
        n = _g.size();
        _stack.reserve(n);
        ids.assign(n, -1);
        low.resize(n);
        instack.assign(n, 0);
        ID = 0;
        rep(u, n) if (ids[u] == -1) dfs(u);
    }
};

int main()
{
    cin >> n >> m;
    g.assign(n, vi());
    g_inv.assign(n, vi());

    rep(i, m)
    {
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g_inv[b - 1].pb(a - 1);
    }

    tarjanSCC tscc(g);
    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for (auto a : v)
        cout << a + 1 << ' ';
}