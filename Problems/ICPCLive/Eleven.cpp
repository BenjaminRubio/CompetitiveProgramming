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

const ll MOD = 1e9 + 7;

string in;
vi digits;
ll choose[110][110];
ll DP[11][101][101][11];

ll dp(int d, int p, int i, int m)
{
    // cerr << d << ' ' << p << ' ' << i << ' ' << m << '\n';

    if (d == 10 && p == 0 && i == 0 && m == 0)
        return 1;
    else if (d == 10)
        return 0;

    if (DP[d][p][i][m] != -1)
        return DP[d][p][i][m];

    if (digits[d])
    {
        ll ans = 0;
        ll aux;
        rep(j, digits[d] + 1)
        {
            if (j > p || digits[d] - j > i)
                continue;
            if (d == 0 && digits[d] - j > i - 1)
                continue;

            // cerr << j << ' ' << (choose[p][j] * choose[i][digits[d] - j]) % MOD << '\n';

            int m_ = (((d * j) - (d * (digits[d] - j))) % 11 + 11) % 11;

            if (d == 0)
            {
                aux = (choose[p][j] * choose[i - 1][digits[d] - j]) % MOD;
                ans = (ans + (dp(d + 1, p - j, i - digits[d] + j, (m + m_) % 11) * aux) % MOD) % MOD;
            }
            else
            {
                aux = (choose[p][j] * choose[i][digits[d] - j]) % MOD;
                ans = (ans + (dp(d + 1, p - j, i - digits[d] + j, (m + m_) % 11) * aux) % MOD) % MOD;
            }
        }
        return DP[d][p][i][m] = (ans + MOD) % MOD;
    }
    else
    {
        return DP[d][p][i][m] = dp(d + 1, p, i, m);
    }
}

int main()
{
    rep(m, 110)
    {
        choose[m][0] = choose[m][m] = 1;
        repx(k, 1, m) choose[m][k] = (choose[m - 1][k] + choose[m - 1][k - 1]) % MOD;
    }

    while (cin >> in)
    {
        digits.assign(10, 0);

        memset(DP, -1, sizeof DP);

        rep(i, in.size())
            digits[in[i] - '0']++;

        // cerr << in.size() << '\n';

        // debugv(digits);
        // break;

        cout << dp(0, in.size() / 2, in.size() - in.size() / 2, 0) << '\n';
    }
}