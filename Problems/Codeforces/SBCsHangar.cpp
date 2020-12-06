#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K; ll A, B;
vector<ll> W;

ll memo[51][51];
ll choose(int n, int k) {
    ll& ans = memo[n][k];
    if (ans != -1) return ans;
    if (k == 0) return ans = 1;
    if (n == k) return ans = 1;
    if (n < k) return ans = 0;
    return ans = choose(n-1,k) + choose(n-1,k-1);
}

ll ways(ll b, ll K)
{
    if (K == 0) return 1;
    
    int i = 0;
    while ((1ll << i) <= b) i++;
    i--;
    if (i < K - 1) return 0;

    return choose(i, K) + ways(b ^ (1ll << i), K - 1);
}

int main()
{
    cin >> N >> K;

    memset(memo, -1, sizeof memo);

    W.resize(N); ll S = 0;
    rep(i, N) { cin >> W[i]; S += W[i]; }

    sort(W.begin(), W.end());

    cin >> A >> B;

    ll b1 = 0, b2 = 0, mm = 0;
    int p = N - 1;
    while (p >= 0 && A >= W[0])
    {
        while (W[p] > A) p--;
        A -= W[p], b1 |= (1ll << p--), mm++;
    }
    p = N - 1;
    while (p >= 0 && B >= W[0])
    {
        while (W[p] > B) p--;
        B -= W[p], b2 |= (1ll << p--);
    }

    cout << ways(b2, K) - ways(b1, K) + (mm == K && A == 0) << '\n';
}