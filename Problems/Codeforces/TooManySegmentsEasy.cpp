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

#define debugx(x) // cerr << #x << ": " << x << endl
#define debugv(v)    //     \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)        //                                \
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

int n, k, l, r;
set<pair<par, int>> s;
set<int> sweep;

int main()
{
    cin >> n >> k;
    rep(i, n)
    {
        cin >> l >> r;
        s.insert({{l, 0}, i});
        s.insert({{r, 1}, i});
    }
    int time = -1;
    int t = -1;
    for (auto e : s)
    {
        if (((e.first.first != time && e.first.second == 1) || (t != e.first.first && t != -1)) && sweep.size() > k)
        {
            cerr << e.first.first << '\n';
            for (auto e_ : sweep)
            {
                cout << e_ << ' ';
            }
            cout << '\n';
            time = e.first.first;
        }
        if (e.first.second == 0)
            sweep.insert(e.second);
        if (e.first.second == 1)
            sweep.erase(e.second);
        t = e.first.first;
    }
}