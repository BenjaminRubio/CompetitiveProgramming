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

int k, n;
string s, t;
vi counts, counts_s, counts_t;
bool done;
vp ops;

int main()
{
    cin >> k;
    rep(t_, k)
    {
        cin >> n >> s >> t;
        counts.assign(27, 0);

        rep(i, n)
        {
            counts[s[i] - 'a']++;
            counts_s[s[i] - 'a']++;
            counts[t[i] - 'a']++;
            counts_t[t[i] - 'a']++;
        }

        done = false;
        rep(i, 27)
        {
            if (!done && counts[i] % 2)
            {
                cout << "No\n";
                done = true;
            }
        }

        if (done)
            continue;

        cout << "Yes\n";
        rep(i, n)
        {
            if (s[i] != t[i])
            {
                done = false;
                repx(j, i + 1, n)
                {
                    if (!done && s[i] == s[j])
                    {
                        done = true;
                        ops.pb({j, i});
                    }
                }

                if (done)
                    continue;

                repx(j, i + 1, n)
                {
                    if (!done && t[i] == t[j])
                    {
                        done = true;
                        ops.pb({i, j});
                    }
                }

                if (done)
                    continue;

                repx(j, i + 1, n)
                {
                    if (!done && s[i] == t[j])
                    {
                        done = true;
                        ops.pb({j, j});
                        ops.pb({j, i});
                    }
                }
            }
        }

        rep(i, ops.size())
                cerr
            << ops[i].first << ' ' << ops[i].second << '\n';
    }
}