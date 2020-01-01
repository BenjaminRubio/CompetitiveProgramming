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

int n, m, a, b;
graph g;
vi candy;
set<int> kids;
vector<set<int>> auxs;

void multi_bfs()
{
    queue<par> q;
    rep(i, n) q.push({i, candy[i]});
    
    while (!q.empty())
    {
        par u = q.front();
        q.pop();

        auxs[u.first].insert(u.second);
        kids.insert(u.second);

        for (int v : g[u.first])
        {
            int gcd_ = gcd(u.second, candy[v]);
            if (auxs[v].count(gcd_) == 0)
            {
                q.push({v, gcd_});
            }
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        g.assign(n, vi());
        auxs.assign(n, set<int>());
        candy.resize(n);

        rep(i, n) cin >> candy[i];
        rep(i, m)
        {
            cin >> a >> b;
            g[a - 1].pb(b - 1);
            g[b - 1].pb(a - 1);
        }

        multi_bfs();

        cout << kids.size() << '\n';

        kids.clear();
        auxs.clear();
    }
}