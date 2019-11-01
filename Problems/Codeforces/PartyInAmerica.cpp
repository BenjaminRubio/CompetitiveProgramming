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
#define invrep(i, b, a) for (int i = b; i >= a; --i)
    
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back
    
#define umap unordered_map
    
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
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
    
const int MOD = 1e9 + 7;
int n, m, k;
vector<vector<char>> pos;
vector<vector<vector<int>>> DP;
    
int dp(int i, int j, int b)
{
    // cerr << "Ins: " << i << ' ' << j << ' ' << b << '\n';
    if (j == m)
        return 1;
    if (DP[i][j][b] != -1)
        return DP[i][j][b];
    
    int i_, j_;
    if (i < n - 1)
    {
        i_ = i + 1;
        j_ = j;
    }
    else
    {
        i_ = 0;
        j_ = j + 1;
    }
    
    int b_ = (b << 2) & ((1 << (2 * n)) - 1);
    // cerr << "Bits: " << b << ' ' << b_ << '\n';
    
    if (pos[i][j] == '-')
    {
        int ans = 0;
        rep(t, k)
        {
            // cerr << "v: " << b << ' ' << t << ' ' << ans << '\n';
            if (i > 0 && (3 & b) == t)
                continue;
            if (j > 0 && ((3 << (2 * (n - 1))) & b) == (t << (2 * (n - 1))))
                continue;
            if (i < n - 1 && pos[i + 1][j] - '1' == t)
                continue;
            if (j < m - 1 && pos[i][j + 1] - '1' == t)
                continue;
            // cerr << t << '\n';
            ans = (ans + dp(i_, j_, b_ | t)) % MOD;
        }
        return DP[i][j][b] = ans;
    }
    else
    {
        int t = pos[i][j] - '1';
        // cerr << i << ' ' << j << ' ' << t << '\n';
        return DP[i][j][b] = dp(i_, j_, b_ | t);
    }
}
    
int main()
{
    cin >> n >> m >> k;
    pos.assign(n, vector<char>(m, 'a'));
    DP.assign(n, graph(m, vi((1 << 2 * n), -1)));
    
    rep(i, n) rep(j, m) cin >> pos[i][j];
    
    rep(i, n) rep(j, m)
    {
        if (pos[i][j] != '-' && i < n - 1 && pos[i][j] == pos[i + 1][j])
        {
            cout << "0\n";
            return 0;
        }
        if (pos[i][j] != '-' && j < m - 1 && pos[i][j] == pos[i][j + 1])
        {
            cout << "0\n";
            return 0;
        }
        if (pos[i][j] != '-' && i > 0 && pos[i][j] == pos[i - 1][j])
        {
            cout << "0\n";
            return 0;
        }
        if (pos[i][j] != '-' && j > 0 && pos[i][j] == pos[i][j - 1])
        {
            cout << "0\n";
            return 0;
        }
    }
    
    // debugm(pos);
    
    cout << dp(0, 0, 0) << '\n';
}