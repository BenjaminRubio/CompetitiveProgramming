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

const int MAX_NUM = 1e6;
vector<bool> is_prime(MAX_NUM + 1, true);
vector<int> primes;
string in;
vi counts;

vi factorial_prime_factorization(int n)
{
    vi prime2exp(MAX_NUM + 1, 0);
    for (int p : primes)
    {
        if (p > n)
            break;
        int e = 0;
        int tmp = n;
        while ((tmp /= p) > 0)
            e += tmp;
        prime2exp[p] = e;
    }
    return prime2exp;
}

int binary_exp(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int limit = floor(sqrt(MAX_NUM));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= MAX_NUM; j += i)
        is_prime[j] = false;
    repx(i, 2, MAX_NUM + 1) if (is_prime[i]) primes.push_back(i);

    while (cin >> in)
    {
        counts.assign(26, 0);
        for (char l : in)
            counts[l - 'a']++;

        vi guide = factorial_prime_factorization(in.size());

        rep(i, 26)
        {
            if (counts[i])
            {
                vi aux = factorial_prime_factorization(counts[i]);
                for (int p : primes)
                    guide[p] -= aux[p];
            }
        }
        int min25 = min(guide[2], guide[5]);
        guide[2] -= min25;
        guide[5] -= min25;

        int ans = 1;
        for (int p : primes)
        {
            if (guide[p])
                ans = (ans * binary_exp(p, guide[p], 10)) % 10;
        }

        cout << ans << '\n';
    }
}