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

int n, q, s, t, x, d;
graph start;
graph stop;
vi times, distances;

int main()
{
    cin >> n >> q;
    multiset<int> ans;
    distances.assign(1e9, -1);
    rep(i, n)
    {
        cin >> s >> t >> x;
        if (s - x >= 0)
        {
            start[s - x].pb(x);
            times.pb(s - x);
        }
        else
            ans.insert(x);
        if (t - x >= 0)
        {
            stop[t - x].pb(x);
            times.pb(t - x);
        }
        else
            ans.erase(x);
    }
    rep(i, 1001)
    {
        for (int k : start[i])
        {
            ans.insert(k);
        }
        for (int k : stop[i])
        {
            ans.erase(ans.lower_bound(k));
        }
        if (ans.empty())
            distances[i] = -1;
        else
            distances[i] = *ans.begin();
    }
    rep(i, q)
    {
        cin >> d;
        cout << distances[d] << '\n';
    }
}