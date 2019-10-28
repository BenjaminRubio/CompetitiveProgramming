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

int n, m, x, y, c, ind;
set<par> v_;
vp pre, now;
wgraph v;

int binsearch(int value)
{
    int i = 0;
    int j = pre.size();
    while (i < j)
    {
        m = (i + j) >> 1;
        if (pre[m].second >= value)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

int main()
{
    cin >> n >> m;

    rep(i, m)
    {
        cin >> x >> y;
        v_.insert({x - 1, y - 1});
    }

    c = -1;
    ind = -1;
    for (auto e : v_)
    {
        if (e.first != c)
        {
            c = e.first;
            v.pb({});
            ind++;
        }
        v[ind].pb(e);
    }

    c = -1;
    pre.pb({0, 0});
    
    rep(i, v.size())
    {
        if (pre.empty())
            break;
        if (v[i][0].first != c + 1)
        {
            now.pb({pre[0].first, n - 1});
            swap(now, pre);
            now.clear();
        }
        c = v[i][0].first;
        ind = 0;
        v[i].pb({c, n});
        for (auto e : v[i])
        {
            if (ind >= e.second)
            {
                ind = e.second + 1;
                continue;
            }
            int search = binsearch(ind);
            if (search < pre.size() && pre[search].first <= e.second - 1)
                now.pb({max(ind, pre[search].first), e.second - 1});
            ind = e.second + 1;
        }
        swap(now, pre);
        now.clear();
    }

    if (!pre.empty() && v[v.size() - 1][0].first != n - 1)
        pre.pb({pre[0].first, n - 1});

    if (!pre.empty() && pre[pre.size() - 1].second == n - 1)
        cout << 2 * n - 2 << '\n';
    else
        cout << -1 << '\n';
}