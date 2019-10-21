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
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int n, m, d, digits;
int mods[10000];

string bfs()
{
    memset(mods, -1, sizeof mods);
    queue<pair<string, int>> q;
    q.push({"", 0});
    while (!q.empty())
    {
        pair<string, int> u = q.front();
        q.pop();
        rep(i, 10)
        {
            if ((1 << i) & digits)
                continue;
            if (u.first.size() == 0 && i == 0)
                continue;
            if (mods[(10 * u.second + i) % n] == -1)
            {
                if ((10 * u.second + i) % n == 0)
                    return u.first + to_string(i);
                mods[(10 * u.second + i) % n] = 0;
                q.push({u.first + to_string(i), (10 * u.second + i) % n});
            }
        }
    }
    return "";
}

int main()
{
    int k = 0;
    while (cin >> n >> m)
    {
        k++;
        digits = 0;
        rep(i, m)
        {
            cin >> d;
            digits ^= (1 << d);
        }
        string res = bfs();
        if (res != "")
            cout << "Case " << k << ": " << res << '\n';
        else
            cout << "Case " << k << ": " << -1 << '\n';
    }
}