#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

vector<ll> primes;

vector<bool> segmentedSieve(ll L, ll R)
{
    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1) isPrime[0] = false;
    return isPrime;
}

ll T, L, U;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    ll lim = sqrt((ll)INT_MAX);
    vector<bool> mark(lim + 1, false);
    for (ll i = 2; i <= lim; ++i) if (!mark[i])
    {
        primes.emplace_back(i);
        for (ll j = i * i; j <= lim; j += i) mark[j] = true;
    }
    while (T--)
    {
        cin >> L >> U;

        vector<bool> ans = segmentedSieve(L, U);
        rep(i, ans.size()) if (ans[i]) cout << L + i << '\n';
    }
}