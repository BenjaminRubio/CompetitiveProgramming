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
#define debugv(v)    //     \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)      //                                  \
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

struct FenwickTree
{
    vi ft;
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    int psq(int b)
    {
        int sum = 0;
        for (; b; b -= (b & -b))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) { return psq(b) - psq(a - 1); }
    void add(int k, int v)
    {
        for (; k < ft.size(); k += (k & -k))
            ft[k] += v;
    }
    void range_add(int i, int j, int v)
    {
        add(i, v);
        add(j + 1, -v);
    }
};

int p, v, x, y, c;
set<int> y_axis;
map<int, int> y_map;
vp plants;
vp vertex;
set<pair<par, par>> events;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> p >> v)
    {
        rep(i, p)
        {
            cin >> x >> y;
            y_axis.insert(y);
            plants.pb({x, y});
        }
        rep(i, v)
        {
            cin >> x >> y;
            y_axis.insert(y);
            vertex.pb({x, y});
        }
        vertex.pb(vertex[0]);

        c = 1;
        for (int e : y_axis)
            y_map[e] = c++;

        rep(i, vertex.size() - 1)
        {
            par v1 = {vertex[i].first, y_map[vertex[i].second]};
            par v2 = {vertex[i + 1].first, y_map[vertex[i + 1].second]};

            if (v1.second < v2.second)
                events.insert({{v1.first, 0}, {v1.second, v2.second}});
            else if (v1.second > v2.second)
                events.insert({{v1.first, 0}, {v2.second, v1.second}});
        }

        rep(i, plants.size())
            events.insert({{plants[i].first, 1}, {y_map[plants[i].second], i + 1}});

        ll ans = 0;
        FenwickTree ft(y_axis.size());
        for (auto e : events)
        {
            if (e.first.second == 0)
                ft.range_add(e.second.first, e.second.second - 1, 1);
            else if (ft.psq(e.second.first) % 2 == 0)
                ans += e.second.second;
        }

        cout << ans << '\n';

        y_axis.clear();
        plants.clear();
        vertex.clear();
        events.clear();
    }
}