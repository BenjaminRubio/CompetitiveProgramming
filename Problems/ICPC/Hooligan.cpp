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

// Dinic apuntes Pablo Messina

struct Dinic
{
    struct edge
    {
        int to, rev;
        ll f, cap;
    };

    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;

    bool bfs(int start, int finish)
    {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail)
        {
            int u = q[head++];
            for (const edge &e : g[u])
            {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap)
                {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }

    ll dfs(int u, ll f)
    {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i)
        {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    Dinic(int n)
    {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }

    void add_edge(int u, int v, ll cap)
    {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }

    ll max_flow(int source, int dest)
    {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest))
        {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int n, m, g, a, b;
char r;
vi puntos, partidos;

int main()
{
    while (cin >> n >> m >> g)
    {
        if (!n)
            break;
        puntos.assign(n, 0);
        partidos.assign(n * (n - 1) / 2, m);
        rep(i, g)
        {
            cin >> a >> r >> b;
            if (r == '<')
            {
                puntos[b] += 2;
            }
            else
            {
                puntos[a] += 1;
                puntos[b] += 1;
            }
            partidos[max(a, b) * (max(a, b) - 1) / 2 + min(a, b)] -= 1;
        }
        int ind = 0;
        repx(i, 1, n)
        {
            puntos[0] += 2 * partidos[ind];
            partidos[ind] = 0;
            ind += i;
        }

        if (puntos[0] <= *max_element(puntos.begin() + 1, puntos.end()))
        {
            cout << "N\n";
            continue;
        }

        Dinic din(n * (n - 1) / 2 + n + 2);

        rep(i, n)
        {
            rep(j, i)
            {
                din.add_edge(0, i * (i - 1) / 2 + j + 1, 2 * partidos[i * (i - 1) / 2 + j]);
                din.add_edge(i * (i - 1) / 2 + j + 1, n * (n - 1) / 2 + i + 1, 2 * partidos[i * (i - 1) / 2 + j]);
                din.add_edge(i * (i - 1) / 2 + j + 1, n * (n - 1) / 2 + j + 1, 2 * partidos[i * (i - 1) / 2 + j]);
            }
        }

        repx(i, 1, n)
        {
            din.add_edge(n * (n - 1) / 2 + i + 1, n * (n - 1) / 2 + n + 1, puntos[0] - puntos[i] - 1);
        }
                                                                        \
        // rep(i, (int)din.g.size())                                                                       \
        // {                                                                                           \
        //     cerr << i << ":";                                                                       \
        //     rep(j, (int)din.g[i].size()) cerr << " {" << din.g[i][j].to << "," << din.g[i][j].cap << "}"; \
        //     cerr << endl;                                                                           \
        // }
        // cerr << '\n';

        ll mf = din.max_flow(0, n * (n - 1) / 2 + n + 1);
        if (mf == 2 * accumulate(partidos.begin() + 1, partidos.end(), 0))
            cout << "Y\n";
        else
            cout << "N\n";
    }
}
