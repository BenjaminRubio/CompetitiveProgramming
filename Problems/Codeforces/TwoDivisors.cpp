#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll N, a;
vector<ll> primes;

void get_primes_up_to(ll n)
{
	vector<bool> is_prime(n + 1, true);
	ll limit = floor(sqrt(n));
	repx(i, 2, limit + 1)
		if (is_prime[i])
			for (ll j = i * i; j <= n; j += i)
				is_prime[j] =  false;
	repx(i, 2, n + 1) if (is_prime[i]) primes.push_back(i);
}

vector<ll> trial_division_precomp(ll n)
{
	vector<ll> factors;
	for (ll d : primes)
    {
		if (d*d > n) break;
		while (n % d == 0)
        {
			factors.push_back(d);
			if ((n /= d) == 1) return factors;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

int main()
{
    get_primes_up_to(1e7 + 1);

    cin >> N;
    vector<ll> l(N, -1), r(N, -1);
    rep(k, N)
    {
        cin >> a;

        vector<ll> f = trial_division_precomp(a);

        ll aux = 1;
        rep(i, f.size() - 1)
        {
            aux *= f[i];
            ll s = aux + (a / aux);
            if (__gcd(s, a) == 1)
            {
                l[k] = aux;
                r[k] = a / aux;
                break;
            }
        }
    }
    rep(i, N) cout << l[i] << ' ';
    cout << '\n';
    rep(i, N) cout << r[i] << ' ';
    cout << '\n';
}