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
#define debugv(v)  //        \
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

struct SparseTableMin
{
    vector<vector<int>> ST;
    vector<int> power2;
    int n;

    SparseTableMin(vector<int> &v)
    {
        n = v.size();
        power2.resize(24);
        power2[0] = 1;
        for (int i = 1; i < 24; i++)
            power2[i] = 2 * power2[i - 1];
        int power = searchPower(n);
        ST.resize(power + 1, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            ST[0][i] = v[i];
        }
        for (int i = 1; i <= power; i++)
        {
            for (int j = 0; j < n - power2[i - 1]; j++)
            {
                ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + power2[i - 1]]);
            }
        }
    }

    int searchPower(int n)
    {
        int l = 0, r = 23;
        for (int m = (l + r) / 2; l != r; m = (l + r) / 2)
        {
            if (power2[m] <= n)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int RMQ(int x, int y)
    {
        int distance = y - x + 1;
        int power = searchPower(distance);
        return min(ST[power - 1][x], ST[power - 1][y - power2[power - 1] + 1]);
    }
};

struct SparseTableMax
{
    vector<vector<int>> ST;
    vector<int> power2;
    int n;

    SparseTableMax(vector<int> &v)
    {
        n = v.size();
        power2.resize(24);
        power2[0] = 1;
        for (int i = 1; i < 24; i++)
            power2[i] = 2 * power2[i - 1];
        int power = searchPower(n);
        ST.resize(power + 1, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            ST[0][i] = v[i];
        }
        for (int i = 1; i <= power; i++)
        {
            for (int j = 0; j < n - power2[i - 1]; j++)
            {
                ST[i][j] = max(ST[i - 1][j], ST[i - 1][j + power2[i - 1]]);
            }
        }
    }

    int searchPower(int n)
    {
        int l = 0, r = 23;
        for (int m = (l + r) / 2; l != r; m = (l + r) / 2)
        {
            if (power2[m] <= n)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int RMQ(int x, int y)
    {
        int distance = y - x + 1;
        int power = searchPower(distance);
        return max(ST[power - 1][x], ST[power - 1][y - power2[power - 1] + 1]);
    }
};

int n, val;
vi v;

int main()
{
    cin >> n;
    v.resize(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    SparseTableMax st1(v);
    rep(i, n)
    {
        cin >> v[i];
    }
    SparseTableMin st2(v);

    ll ans = 0;

    rep(k, n)
    {
        int i1 = k;
        int j = n;
        while (i1 < j)
        {
            int m = (i1 + j) / 2;
            if (st1.RMQ(k, m) >= st2.RMQ(k, m))
                j = m;
            else
                i1 = m + 1;
        }
        int i2 = k;
        j = n;
        while (i2 < j)
        {
            int m = (i2 + j) / 2;
            if (st1.RMQ(k, m) > st2.RMQ(k, m))
                j = m;
            else
                i2 = m + 1;
        }
        ans += i2 - i1;
    }

    cout << ans << '\n';
}
