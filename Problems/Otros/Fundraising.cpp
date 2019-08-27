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

int n, b, f, d;
set<pair<par, int>> guests;

const int MAXLEN = 1000000;

int LIS(set<pair<par, int>> &values)
{
    pair<par, int> q[MAXLEN + 1];
    int len = 0;
    q[0] = {{-1, -1}, -1};
    for (auto val : values)
    {
        if (q[len].first.first < val.first.first && q[len].first.second < val.first.second)
        {
            q[++len] = val;
        }
        else
        {
            int l = 1, r = len;
            while (l < r)
            {
                int m = (l + r) >> 1;
                if (!(q[m].first.first < val.first.first && q[m].first.second < val.first.second))
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
            q[l] = val;
        }
    }
    return len;
}

int main()
{
    while (cin >> n)
    {
        rep(i, n)
        {
            cin >> b >> f >> d;
            guests.insert({{b, f}, d});
        }
        for (auto i : guests)
        {
            b = i.first.first;
            f = i.first.second;
            d = i.second;
            cout << b << ' ' << f << ' ' << d << '\n';
        }
        guests.clear();
        cout << '\n';
    }
}