#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll M, P, N;
vector<pair<ll, ll>> E;

bool trial_division_precomp(ll n, vector<ll> &ans)
{
	for (auto &e : E) {
        ll d = e.first, c = 0;
		while (c < e.second && n % d == 0) {
			ans.push_back(d); c++;
			if ((n /= d) == 1ll) return true;
		}
        if (n % d == 0) return false;
	}
	return false;
}

void test_case()
{
    cin >> M;

    ll tot = 0, sum = 0;

    E.resize(M);
    rep(i, M) { cin >> E[i].ff >> E[i].ss; tot += E[i].ss; sum += E[i].ss * E[i].ff; }

    ll ans = 0;
    for (ll x = 2; x <= 1000000; x++)
    {
        vector<ll> f;
        if (trial_division_precomp(x, f))
        {
            ll aux = sum;
            for (int ff : f) aux -= ff;

            if (x == aux) ans = max(ans, x);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    ll TT; cin >> TT;
    rep(tt, TT)
    {
        cout << "Case #" << tt + 1 << ": ";
        test_case();
    }
}