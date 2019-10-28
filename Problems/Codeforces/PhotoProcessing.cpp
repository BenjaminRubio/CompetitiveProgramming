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

int n, k, m;
vi v;
vi s;

int dp(int i)
{
    if (i < k - 1)
        return 0;
    if (v[i] - v[0] <= m)
        return 1;
    int i_ = k;
    int j_ = i - k + 2;
    while (i_ < j_)
    {
        int m_ = (i_ + j_) >> 1;
        if (v[i] - v[m_] <= m)
            j_ = m_;
        else
            i_ = m_ + 1;
    }
    if (i - k >= 0 && i_ - 2 >= 0 && s[i - k] - s[i_ - 2] > 0)
        return 1;
    return 0;
}

bool solve()
{
    int sum = 0;
    rep(i, n)
    {
        sum += dp(i);
        s[i] = sum;
    }
    return dp(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);

    if (k == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    rep(i, n)
            cin >>
        v[i];

    sort(v.begin(), v.end());

    // debugv(v);

    int i = 0;
    int j = v[v.size() - 1] - v[0];
    s.assign(n, 0);
    while (i < j)
    {
        m = (i + j) >> 1;
        if (solve())
            j = m;
        else
            i = m + 1;
        // debugv(DP);
    }

    cout << i << '\n';
}