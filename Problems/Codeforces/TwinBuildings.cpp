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
#define debugm(m)                                        \
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

int n, l, w;
set<pair<int, pair<par, int>>> lands;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(1);

    cin >> n;

    rep(i, n)
    {
        cin >> l >> w;
        lands.insert({l * w, {{l, w}, i}});
        lands.insert({l * w, {{w, l}, i}});
    }

    double ans = 0;
    int cid1 = -1;
    par cval1 = {0, 0};
    int cid2 = -1;
    par cval2 = {0, 0};

    for (auto e : lands)
    {
        // cerr << e.first.first << ' ' << e.first.second << '\n';
        ans = max(ans, e.first / 2.0);
        if (e.first > ans)
        {
            if (e.second.second != cid2 && (double) min(e.second.first.first, cval2.first) * min(e.second.first.second, cval2.second) > ans)
                cid1 = -1;
            else if (e.second.second != cid1 && (double) min(e.second.first.first, cval1.first) * min(e.second.first.second, cval1.second) > ans)
                cid2 = -1;
        }
        if (cid1 == -1)
        {
            cid1 = e.second.second;
            cval1 = e.second.first;
        }
        else if (e.second.second != cid1 && cid2 == -1)
        {
            cid2 = e.second.second;
            cval2 = e.second.first;
        }
        ans = max(ans, (double) min(cval1.first, cval2.first) * min(cval1.second, cval2.second));
    }

    cerr << cval1.first << ' ' << cval1.second << '\n';
    cerr << cval2.first << ' ' << cval2.second << '\n';
    cout << ans << '\n';
}