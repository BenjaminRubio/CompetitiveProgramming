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
#define debugv(v)  //       \
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

int x, n, m, t, a, b;
vp rides;
graph g;
int DP[1001][1001];

int dp(int pos, int time_left)
{
    if (time_left < rides[0].first)
        return 1e9;
    if (time_left == rides[0].first and pos != 0)
        return 1e9;
    if (time_left == rides[0].first and pos == 0)
        return DP[pos][time_left] = rides[0].second;
    if (DP[pos][time_left] != -1)
        return DP[pos][time_left];
    int ans = 1e9;

    ans = min(ans, dp(pos, time_left - rides[pos].first));
    for (int r : g[pos])
    {
        ans = min(ans, dp(r, time_left - rides[pos].first - t));
    }

    if (ans != 1e9)
        return DP[pos][time_left] = ans + rides[pos].second;
    return DP[pos][time_left] = ans;
}

int main()
{
    cin >> x >> n >> m >> t;

    g.resize(n);
    memset(DP, -1, sizeof DP);

    rep(i, m)
    {
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g[b - 1].pb(a - 1);
    }

    rep(i, n)
    {
        cin >> a >> b;
        rides.pb({a, b});
    }

    int ans = dp(0, x);

    if (ans == 1e9)
        cout << "It is a trap.\n";
    else
        cout << ans << '\n';
}