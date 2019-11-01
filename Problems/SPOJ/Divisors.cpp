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
#define invrep(i, b, a) for (int i = b; i >= a; --i)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
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

const int MAXNUM = 10000;
vector<bool> is_prime(MAXNUM + 1, true);
graph divisors(MAXNUM + 1, vi());
vi counters;
set<int> sets_divisors[100000];
int T, n, x, c;
string op;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    repx(i, 2, MAXNUM + 1)
    {
        if (is_prime[i]) for (int j = i + i; j <= MAXNUM; j += i)
            is_prime[j] = false;
        else for (int j = i; j <= MAXNUM; j += i)
            divisors[j].pb(i);
    }

    cin >> T;
    rep(t, T)
    {
        counters.assign(MAXNUM + 1, 0);

        cin >> n;

        c = 0;
        rep(i, n)
        {
            cin >> op;
            if (op == "UPD")
            {
                cin >> op >> x;
                if (op == "ADD")
                {
                    c++;
                    for (int d : divisors[x])
                    {
                        sets_divisors[counters[d]].insert(d);
                        counters[d]++;
                    }
                }
                if (op == "REM")
                {
                    c--;
                    for (int d : divisors[x])
                    {
                        counters[d]--;
                        sets_divisors[counters[d]].erase(d);
                    }
                }
            }
            else
            {
                if (c > 0)
                {
                    cout << 1 << ' ';
                    for (int d : sets_divisors[c - 1])
                        cout << d << ' ';
                    cout << '\n';
                }
                else
                {
                    cout << "-1\n";
                }
            }
        }

        rep(i, c)
            sets_divisors[i].clear();
    }
}