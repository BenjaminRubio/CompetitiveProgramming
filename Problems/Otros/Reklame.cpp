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

int n, k, r;
graph d;
vi b;

int predicate(int i, int id)
{
    // cerr << i << ' ' << id << ' ' << m << '\n';
    if (id >= n)
        return d[id - 1][d[id - 1].size() - 1];

    int ans = 1e9;
    rep(j, 8)
    {
        bool able = true;
        rep(t, d[id].size())
        {
            if (b[i + j + d[id][t] - 1] == k)
                able = false;
        }
        if (able)
        {
            rep(t, d[id].size())
                b[i + j + d[id][t] - 1]++;
            ans = min(ans, j + predicate(i + j, id + 1));
            rep(t, d[id].size())
                b[i + j + d[id][t] - 1]--;
        }
    }
    return ans;
}

// int binsearch()
// {
//     int i = 0;
//     int j = n * 7;
//     while (i < j)
//     {
//         int m = (i + j) >> 1;
//         b.assign(m, 0);
//         if (predicate(0, 0, m))
//             j = m;
//         else
//             i = m + 1;
//     }
//     return i;
// }

int main()
{
    cin >> n >> k;
    d.resize(n);
    rep(i, n)
    {
        cin >> r;
        d[i].resize(r);
        d[i][0] = 1;
        rep(j, r - 1)
            cin >> d[i][j + 1];
    }

    b.assign(7 * n, 0);

    cout << predicate(0, 0) << '\n';
}