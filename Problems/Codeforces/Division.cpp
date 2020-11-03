#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

vector<pair<ll, ll>> trial_division(ll n)
{
	vector<pair<ll, ll>> factors;
	for (ll d = 2; d * d <= n; d++)
    {
        ll c = 1;
        while (n % d == 0) c *= d, n/= d;
        if (c > 1) factors.emplace_back(d, c);
        if (n == 1) return factors;
    }
	if (n > 1) factors.emplace_back(n, n);
	return factors;
}

ll T, p, q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> p >> q;

        if (p % q) { cout << p << '\n'; continue; }

        vector<pair<ll, ll>> mq = trial_division(q);
        int N = mq.size();

        ll ans = LLONG_MIN;
        bool o1 = 0; int i = 0, j = 0;
        while (i < N)
        {
            ll c = 1, d = mq[i].ff, r = p;
            while (r % q == 0) r /= d;
            ans = max(r, ans), i++;
        }
        
        cout << ans << '\n';
    }
}