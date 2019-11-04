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

const int MAX_NUM = 1e5;
int q, n, k;
vi rem, max_prime, primes;
graph order;

int binsearch(int ind, int n)
{
    int i = 0;
    int j = order[ind].size();
    while (i < j)
    {
        int m = (i + j) >> 1;
        if (order[ind][m] > n)
            j = m;
        else
            i = m + 1;
    }
    return i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    sum_primes.assign(MAX_NUM + 1, 0);
    primes.assign(MAX_NUM + 1, -1);
    rem.assign(MAX_NUM + 1, -1);
    int limit = floor(sqrt(MAX_NUM));
    repx(i, 2, limit + 1) if (max_prime[i] == 0) for (int j = i * i; j <= MAX_NUM; j += i)
    {
        max_prime[j] = i;
        if (rem[j] == -1)
            n = j / i;
        else
            n = rem[j] / i;
        while (n % i == 0)
            n /= i;
        rem[j] = n;
    }

    int n_primes = 0;

    repx(i, 2, MAX_NUM + 1)
    {
        primes[i] = n_primes - 1;
        if (max_prime[i] == 0)
            primes[i] = n_primes++;
    }

    order.resize(n_primes + 1);

    repx(i, 2, MAX_NUM + 1)
    {
        if (max_prime[i] == 0)
            max_prime[i] = i;
        max_prime[i] = max(max_prime[i], rem[i]);
        // cerr << max_prime[i] << ' ' << primes[max_prime[i]] << '\n';
        order[primes[max_prime[i]]].pb(i);
    }

    cin >> q;
    rep(i, q)
    {
        cin >> n >> k;

        if (k >= n)
        {
            cout << n - 1 << '\n';
            continue;
        }

        int ans = 0;
        int prime_k = primes[k];
        rep(j, prime_k + 1)
        {
            ans += binsearch(j, n);
        }

        cout << ans << '\n';
    }
}
