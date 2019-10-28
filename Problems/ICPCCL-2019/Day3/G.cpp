#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
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

int n, l;
vi heights, widths;
int memo[201][3001];
const int MOD = (int)1e9 + 7;

int f(int i, int length)
{
    if (length == 0)
        return memo[i][length] = 1;
    if (memo[i][length] != -1)
        return memo[i][length];

    int result = 0;
    rep(j, 2 * n)
    {
        if (heights[i] == widths[j] and length - widths[j] >= 0 and 
            heights[j] >= 0 and (i % n != j % n))
        {
            result += f(j, length - widths[j]);
            result %= MOD;
        }
    }
    return memo[i][length] = result;
}

int main()
{
    cin >> n >> l;
    heights.assign(2 * n, -1);
    widths.assign(2 * n, -1);
    memset(memo, -1, sizeof(memo));
    rep(i, n)
    {
        cin >> widths[i] >> heights[i];
        if (heights[i] != widths[i])
        {
            heights[n + i] = widths[i];
            widths[n + i] = heights[i];
        }
    }
    int result = 0;
    rep(i, 2 * n)
    {
        if (heights[i] >= 0)
        {
            result += f(i, l - widths[i]);
            result %= MOD;
        }
    }

    cout << result << '\n';
}
