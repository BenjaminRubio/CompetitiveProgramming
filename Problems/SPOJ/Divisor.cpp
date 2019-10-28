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

vi divisors;

bool check2(int n, vector<int> &primes)
{
    vector<int> factors;
    for (int d : primes)
    {
        if (d * d > n)
            break;
        while (n % d == 0)
        {
            factors.push_back(d);
            if ((n /= d) == 1)
                return factors.size() == 2;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors.size() == 2;
}

bool check1(int n, vector<int> &primes)
{
    int v = n;
    int ans = 1;
    for (int d : primes)
    {
        int c = 1;
        if (d * d > n)
            break;
        while (v % d == 0)
        {
            c++;
            v /= d;
        }
        ans *= c;
    }
    if (v > 1)
        ans *= 2;
    // cerr << n << ' ' << ans << ' ' << divisors[ans] << ' ' << check2(ans, primes) << '\n';
    return divisors[ans] == 2 && check2(ans, primes);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 1e6;
    divisors.assign(n + 1, 0);
    int limit = floor(sqrt(n));
    repx(i, 2, limit + 1) if (divisors[i] == 0) for (int j = i + i; j <= n; j += i)
    {
        divisors[j]++;
    }

    vector<int> primes;
    repx(i, 2, n + 1) if (divisors[i] == 0) primes.push_back(i);

    // debugv(divisors);

    int c = 0;
    repx(i, 2, n + 1)
    {
        if (check1(i, primes))
        {
            c++;
            if (c == 9)
            {
                cout << i << '\n';
                c = 0;
            }
        }
    }

}