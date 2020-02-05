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

int n, l, r;
set<pair<par, int>> events;
set<int> tvs, tvs_on;

int main()
{
    cin >> n;

    rep(i, n)
    {
        cin >> l >> r;
        events.insert({{l, 0}, i + 1});
        events.insert({{r, 1}, i + 1});
        tvs.insert(i + 1);
    }

    int time = -1;
    int type = 0;
    bool saque = false;

    for (auto e : events)
    {
        int t = e.first.first;
        int p = e.first.second;
        int index = e.second;

        if (time < t)
        {

            if (tvs_on.size() == 1 && (time != t - 1 || !saque))
                tvs.erase(*tvs_on.begin());
            if (p == 0)
                tvs_on.insert(index);
            if (p == 1)
            {
                if (tvs_on.size() == 1)
                    tvs.erase(*tvs_on.begin());
                tvs_on.erase(index);
            }
        }
        else
        {
            if (p > type)
            {
                if (tvs_on.size() == 1)
                    tvs.erase(*tvs_on.begin());
                tvs_on.erase(index);
            }
            else
            {
                if (p == 0)
                    tvs_on.insert(index);
                else
                    tvs_on.erase(index);
            }
        }

        time = t;
        type = p;
        saque = p;
    }

    if (!tvs.empty())
        cout << *tvs.begin() << '\n';
    else
        cout << -1 << '\n';
}