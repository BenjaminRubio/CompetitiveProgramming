#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ff first
#define ss second

vector<pair<ll, ll>> trial_division_precomp(ll n, vector<ll>& primes) {
	vector<pair<ll, ll>> factors;
	for (ll d : primes) {
		if (d*d > n) break;
        ll c = 0;
		while (n % d == 0) {
			c++;
			if ((n /= d) == 1) break;
		}
        if (c) factors.emplace_back(d, c);
        if (n == 1) return factors;
	}
	if (n > 1) factors.emplace_back(n, 1);
	return factors;
}

ll n, a;

int main()
{
    cin >> n;

    vector<bool> is_prime(200000 + 1, true);
	ll limit = floor(sqrt(200000));
	repx(i, 2, limit + 1)
		if (is_prime[i])
			for (ll j = (i * i); j <= 200000; j += i)
				is_prime[j] = false;
	vector<ll> primes;
	repx(i, 2, 200000 + 1) if (is_prime[i]) primes.push_back(i);
    map<ll, ll> M, m, cnt;
    for (ll p : primes) M[p] = 1e9, m[p] = 1e9;

    rep(_, n)
    {
        cin >> a;
        vector<pair<ll, ll>> f = trial_division_precomp(a, primes);

        for (auto &e : f)
        {
            cnt[e.ff]++;
            if (e.ss < M[e.ff]) { m[e.ff] = M[e.ff]; M[e.ff] = e.ss; }
            else if (e.ss < m[e.ff]) m[e.ff] = e.ss;
        }
    }

    ll ans = 1;
    for (ll p : primes)
    {
        if (cnt[p] == n) while (m[p]--) ans *= p;
        else if (cnt[p] == n - 1) while (M[p]--) ans *= p;
    }

    cout << ans << '\n';
}