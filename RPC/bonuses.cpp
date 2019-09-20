#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
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
#define debugm(m)  //                                      \
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

struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N)
    {
        FT.resize(N + 1, 0);
    }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    int query(int i, int j)
    {
        return query(j) - query(i - 1);
    }

    void update(int i, int v)
    {
        int s = query(i, i);
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v - s;
    }

    //Queries puntuales, Updates por rango
    void update(int i, int j, int v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};

int n, s, t, a, b, t_;
vi paid, multipliers;
vector<pair<int, par>> queries;
graph g = {{}};
vi visited = {0};
vector<ll> order = {0};
vector<par> ranges = {{0, 0}};

void dfs(int u)
{
    visited[u] = 1;

    for (auto v : g[u])
    {
        if (!visited[v])
        {
            order.pb(v);
            ranges[v].first = t_;
            t_++;
            dfs(v);
            ranges[v].second = t_ - 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    int id = 1;

    rep(i, n)
    {
        cin >> t;

        if (t == 1 or t == 4)
        {
            cin >> a;
        }
        else
        {
            cin >> a >> b;
        }
        if (t == 1)
        {
            g[a - 1].pb(id++);
            g.pb({});
            visited.pb(0);
            ranges.pb({0, 0});
        }
        queries.pb({t, {a, b}});
    }

    ranges[0].first = 0;
    t_++;
    dfs(0);
    ranges[0].second = t_ - 1;
    paid.assign(order.size(), 0);
    multipliers.assign(order.size(), 0);
    multipliers[0] = s;

    FenwickTree ft(order.size());

    rep(i, n)
    {
        t = queries[i].first;
        a = queries[i].second.first;
        b = queries[i].second.second;

        cerr << "linea " << t << '\n';
        rep(j, order.size())
                cerr
            << ft.query(j + 1) << '\n';

        if (t == 1)
        {
            int in = ft.query(ranges[a - 1].first + 1);
            ft.update(ranges[a - 1].first + 1, ranges[a - 1].first + 1, 0);
            multipliers[a - 1] = s;
        }
        if (t == 2)
        {
            int in = ft.query(ranges[a - 1].first + 1);
            paid[a - 1] += in * multipliers[a - 1];
            ft.update(ranges[a - 1].first + 1, ranges[a - 1].first + 1, 0);
            multipliers[a - 1] = b;
        }
        if (t == 3)
            ft.update(ranges[a - 1].first + 1, ranges[a - 1].second + 1, b);
        if (t == 4)
        {
            int in = ft.query(ranges[a - 1].first + 1);
            paid[a - 1] += in * multipliers[a - 1];
            ft.update(ranges[a - 1].first + 1, ranges[a - 1].first + 1, 0);
            cout << paid[a - 1] << '\n';
        }
    }
}