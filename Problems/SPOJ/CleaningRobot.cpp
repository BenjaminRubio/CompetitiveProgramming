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
#define invrep(i, a, b) for (int i = a; i > (int)b; i--)

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

#define debugx(x) // cerr << #x << ": " << x << endl
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
#define debugmp(m) //                                                                       \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int d1, d2, d;
par pos;
vector<vector<char>> m;
graph DP;
graph bits, cost;
vi dx = {0, 1, 0, -1};
vi dy = {-1, 0, 1, 0};

void bfs(int s)
{
    int index1 = bits[s / d2][s % d2];
    int depth[d1 * d2];
    memset(depth, -1, sizeof(int) * d1 * d2);
    queue<int> q;
    q.push(s);
    depth[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int i = u / d2;
        int j = u % d2;
        rep(k, 4)
        {
            int i_ = i + dx[k];
            int j_ = j + dy[k];
            if (i_ >= 0 && i_ < d1 && j_ >= 0 && j_ < d2 && m[i_][j_] != 'x')
            {
                int v = i_ * d2 + j_;
                if (depth[v] == -1)
                {
                    depth[v] = depth[u] + 1;
                    q.push(v);
                    if (bits[i_][j_] != -1)
                        cost[index1][bits[i_][j_]] = depth[v];
                }
            }
        }
    }
}

int dp(int i, int b)
{
    // cerr << i << ' ' << b << '\n';
    if (b == 0)
        return 0;
    if (DP[i][b] != -1)
        return DP[i][b];
    int ans = 1e9;
    for (int j = 0, b_ = 1; b_ <= b; ++j, b_ <<= 1)
    {
        if (b & b_)
        {
            assert(i != j);
            ans = min(ans, cost[i][j] + dp(j, b & ~b_));
        }
    }
    return DP[i][b] = ans;
}

int main()
{
    while (cin >> d2 >> d1)
    {
        if (d1 == 0 && d2 == 0)
            break;

        m.assign(d1, vector<char>(d2, '.'));
        bits.assign(d1, vi(d2, -1));

        d = 0;
        rep(i, d1) rep(j, d2)
        {
            cin >> m[i][j];
            if (m[i][j] == '*' || m[i][j] == 'o')
            {
                bits[i][j] = d;
                d++;
                if (m[i][j] == 'o')
                    pos = {i, j};
            }
        }

        cost.assign(d, vi(d, 1e9));

        rep(i, d1) rep(j, d2)
        {
            if (bits[i][j] != -1)
            {
                bfs(i * d2 + j);
            }
        }

        DP.assign(d1 * d2, vi(1 << d, -1));

        // debugm(cost);
        int ans = dp(bits[pos.first][pos.second], ((1 << d) - 1) ^ (1 << bits[pos.first][pos.second]));

        if (ans < 1e9)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}