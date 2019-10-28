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

#define debugx(x)  // cerr << #x << ": " << x << endl
#define debugv(v)  //     \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                  \
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

int T, n, v, m;
vector<vector<char>> mat;
vi rows;
vi cols;
ll DP[144][121][(1 << 12) - 1][(1 << 12) - 1];

par next_pos(par pos)
{
    int i = pos.first;
    int j = pos.second;
    if (j < n - 1)
        return {i, j + 1};
    return {i + 1, 0};
}

ll backtracking(int i, int j, int delta, int rest)
{
    if (mat[i][j] == '.' && rest == 1)
    {
        if (delta > 0 && delta <= n && (rows[i] & (1 << delta)) == 0 && (cols[j] & (1 << delta)) == 0)
            return 1;
        return 0;
    }

    int i_ = next_pos({i, j}).first;
    int j_ = next_pos({i, j}).second;
    if (mat[i][j] == '.')
    {
        ll ans = 0;
        repx(k, 1, min(delta - rest + 2, n + 1))
        {
            if (((1 << k) & rows[i]) == 0 && ((1 << k) & cols[j]) == 0)
            {
                rows[i] ^= (1 << k);
                cols[j] ^= (1 << k);
                ans += backtracking(i_, j_, delta - k, rest - 1);
                rows[i] ^= (1 << k);
                cols[j] ^= (1 << k);
            }
        }
        return ans;
    }
    else
        return backtracking(i_, j_, delta, rest);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    rep(k, T)
    {
        m = 0;
        cin >> n >> v;
        mat.assign(n, vector<char>(n, 'a'));
        rows.assign(n, 0);
        cols.assign(n, 0);

        rep(i, n) rep(j, n)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '.')
                m++;
        }

        if (m * n < v)
            cout << "Case " << k + 1 << ": 0\n";
        else if (m * n == v)
            cout << "Case " << k + 1 << ": 1\n";
        else
            cout << "Case " << k + 1 << ": " << backtracking(0, 0, v, m) << '\n';
    }
}