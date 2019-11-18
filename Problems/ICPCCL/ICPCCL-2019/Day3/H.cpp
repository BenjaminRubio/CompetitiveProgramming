#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
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

int T, n;
vi velocities, memo;

ll f(int b)
{
    if (b == 0)
    {
        return 0;
    }
    if (memo[b] != -1)
        return memo[b];

    ll ans = 2e9;
    rep(i, n)
    {
        repx(j, i + 1, n)
        {
            if ((1 << i) & b and (1 << j) & b)
            {
                ll ida = velocities[j];
                int x;
                rep(k, n)
                {
                    if (((~b) ^ (1 << i) ^ (1 << j)) & (1 << k))
                    {
                        x = k;
                        break;
                    }
                }
                if ((b ^ (1 << i) ^ (1 << j)) == 0)
                {
                    ans = min(ans, ida);
                }
                else
                {
                    ans = min(ans, ida + velocities[x] + f((b ^ (1 << i) ^ (1 << j)) | (1 << x)));
                }
            }
        }
    }
    return memo[b] = ans;
}

int main()
{
    cin >> T;
    rep(k, T)
    {
        cin >> n;
        velocities.assign(n, 0);
        memo.assign((1 << n), -1);

        rep(i, n) { cin >> velocities[i]; }

        sort(velocities.begin(), velocities.end());

        if (n == 1)
            cout << velocities[0] << '\n';
        else if (n == 2)
            cout << velocities[1] << '\n';
        else
            cout << f((1 << n) - 1) << '\n';
    }
}
