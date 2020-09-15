#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll N, C;

int main()
{
    cin >> N;

    vector<bool> is_prime(N + 1, true); ll limit = floor(sqrt(N + 1));
	repx(i, 2, limit + 1) if (is_prime[i]) for (ll j = i * i; j <= N; j += i)
        is_prime[j] =  false;
	vector<ll> P;
	repx(i, 2, N + 1) if (is_prime[i]) P.push_back(i);

    ll T = N, B = sqrt(P.size()) + 1ll, ans = 1;
    vector<bool> ON(N, true);

    rep(i, P.size() + 1)
    {
        if (ans == 1 && i && (i % B == 0 || i == P.size()))
        {
            cout << "A " << 1 << endl;
            cin >> C;

            if (C > T) repx(j, max(0ll, i - B), min(i, (ll)P.size()))
            {
                cout << "A " << P[j] << endl;
                cin >> C;

                if (C)
                {
                    ans *= P[j];
                    ll p = P[j] * P[j];
                    if (p <= N)
                    {
                        cout << "A " << p << endl;
                        cin >> C;

                        while (C && p <= N)
                        {
                            ans *= P[j], p *= P[j];
                            if (p <= N)
                            {
                                cout << "A " << p << endl;
                                cin >> C;
                            }
                        }
                    }
                }
            }
        }
        if (i == P.size()) break;

        cout << "B " << P[i] << endl;
        cin >> C; T -= C;

        ll R = 1, p = P[i];
        while (N >= p * P[i]) { R++; p*= P[i]; }

        if (ans > 1 && C > R) 
        {
            ans *= P[i];
            ll p = P[i] * P[i];

            if (p <= N)
            {
                cout << "A " << p << endl;
                cin >> C;

                while (C && p <= N)
                {
                    ans *= P[i], p *= P[i];
                    if (p <= N)
                    {
                        cout << "A " << p << endl;
                        cin >> C;
                    }
                }
            }
        }
    }

    cout << "C " << ans << endl;
}