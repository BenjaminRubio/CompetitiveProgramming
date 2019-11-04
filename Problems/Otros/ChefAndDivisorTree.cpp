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

int a, b;
vector<bool> is_prime;
vector<ll> primes;

ll factor(ll y)
{
    ll x = y;
    if (x == 1)
        return 0;
    ll max_aux = -1;
    ll max_arg = -1;
    ll res = 1;
    for (ll d : primes)
    {
        ll aux = 0;
        if (d * d > x)
            break;
        while (x % d == 0)
        {
            aux++;
            x /= d;
        }
        if (aux > max_aux)
        {
            max_aux = aux;
            max_arg = d;
        }
        res *= (aux + 1);
    }
    if (x > 1)
    {
        res *= 2;
        if (1 > max_aux)
        {
            max_aux = 1;
            max_arg = x;
        }
    }
    return res + factor(y / max_arg);
}

int main()
{
    cin >> a >> b;
    int n = 1e6;
    int limit = floor(sqrt(n));
    is_prime.assign(n + 1, true);
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    repx(i, 2, n + 1) if (is_prime[i])
        primes.pb(i);

    // cerr << primes[primes.size() - 1] << '\n';

    ll ans = 0;
    for (ll i = a; i <= b; i++)
    {
        // cerr << i << ' ' << factor(i) << '\n';
        ans += factor(i);
    }

    cout << ans << '\n';
}