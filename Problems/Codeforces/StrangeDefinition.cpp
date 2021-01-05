#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N, Q; ll w;
vector<ll> A, P;

vector<ll> get_primes_up_to(int n) {
	vector<bool> is_prime(n + 1, true);
	int limit = floor(sqrt(n));
	repx(i,2,limit+1)
		if (is_prime[i])
			for (int j = i*i; j <= n; j += i)
				is_prime[j] =  false;
	vector<ll> primes;
	repx(i,2,n) if (is_prime[i]) primes.push_back(i);
	return primes;
}

ll square(ll x)
{
	ll ans = 1;
	for (ll d : P)
    {
		if (d * d > x) break;
        ll cnt = 0;
		while (x % d == 0) cnt++, x /= d;
        if (cnt & 1ll) ans *= d;
	}
	if (x > 1) ans *= x;
	return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    P = get_primes_up_to(1e6);

    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        vector<ll> S(N); multiset<ll> ms;
        rep(i, N) { S[i] = square(A[i]); ms.insert(S[i]); }

        ll M = 0, ss = 0; set<ll> s;
        rep(i, N) if (!s.count(S[i]))
        {
            ll c = ms.count(S[i]); s.insert(S[i]);
            M = max(M, c);
            if (S[i] == 1) ss += c;
            else if ((c & 1ll) == 0) ss += c;
        }

        cin >> Q;
        while (Q--)
        {
            cin >> w;

            if (w == 0) cout << M << '\n';
            else cout << max(M, ss) << '\n';
        }
    }
}