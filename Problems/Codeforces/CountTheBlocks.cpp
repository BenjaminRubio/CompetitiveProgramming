#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

const ll MOD = 998244353;

int N;
ll p[200000 + 1];

int main()
{
    p[0] = 1;
    rep(i, 200000) p[i + 1] = (p[i] * 10) % MOD;

    cin >> N;

    ll sum1 = 0, sum2 = 0;
    vector<ll> ans;
    rep(i, N)
    {
        ll tot = ((i + 1) * p[i + 1]) % MOD;
        ans.push_back((tot - sum2 + MOD) % MOD);
        sum1 = (sum1 + (tot - sum2 + MOD) % MOD) % MOD;
        sum2 =  (sum1 + tot) % MOD;
    }
    rep(i, N) cout << ans[N - i - 1] << ' ';
    cout << '\n';
}