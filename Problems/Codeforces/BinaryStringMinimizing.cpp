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

ll T, n, k;
string x;
vector<ll> pos0;

int main()
{
    cin >> T;

    rep(t, T)
    {
        cin >> n >> k;
    
        cin >> x;
        n = x.size();
        rep(i, n)
        {
            if (x[i] == '0')
                pos0.pb(i);
        }

        // debugv(pos0);

        ll ind = 0;
        ll i_ = 0;
        while (i_ < n && k && ind < pos0.size())
        {
            ll p = min(k, pos0[ind] - i_);
            k -= p;
            pos0[ind] -= p;
            i_ = pos0[ind] + 1;
            ind++;
        }
        // cerr << k << '\n';

        ind = 0;
        rep(i, n)
        {
            if (ind < pos0.size() && pos0[ind] == i)
            {
                cout << 0;
                ind++;
            }
            else
                cout << 1;
        }
        cout << '\n';

        pos0.clear();
    }
}
