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
    
int N;
vi primes, nums, factors, powers;
graph memo;
const int MOD = 1e9 + 7;
    
void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    int limit = floor(sqrt(n));
    repx(i, 2, limit + 1) if (is_prime[i]) for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    repx(i, 2, n + 1) if (is_prime[i]) primes.push_back(i);
}
    
int factor(int num)
{
    int b = 0;
    rep(i, primes.size())
    {
        int p = primes[i];
        while (num % p == 0)
        {
            b ^= (1 << i);
            num /= p;
        }
    }
    return b;
}
    
int f(int i, int b)
{
    if (i == 0 and b == 0)
        return 1;
    if (i == 0)
        return 0;
    if (memo[i][b] != -1)
        return memo[i][b];
    if (nums[i] == 0)
        return memo[i][b] = f(i - 1, b);
    return memo[i][b] = ((ll) powers[nums[i] - 1] * f(i - 1, b) +
                            (ll) powers[nums[i] - 1] * f(i - 1, b ^ factors[i])) %
                        MOD;
}
    
int main()
{
    sieve(70);
    cin >> N;
    memo.assign(71, vi((1 << 19), -1));
    nums.assign(71, 0);
    powers.assign(1e5, -1);
    factors.assign(71, -1);
    
    powers[0] = 1;
    repx(i, 1, N) powers[i] = (2 * powers[i - 1]) % MOD;
    
    rep(i, N)
    {
        int num;
        cin >> num;
        nums[num]++;
        if (nums[num] == 1)
            factors[num] = factor(num);
    }
    cout << f(70, 0) - 1 << '\n';
}