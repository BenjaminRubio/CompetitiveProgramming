#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll T, N;
vector<ll> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        vector<ll> m(N + 1, 0);
        rep(i, N) { cin >> A[i]; m[A[i]]++; }

        ll ans = 0;
        vector<ll> s;
        rep(i, N)
        {
            s.assign(N + 1, 0);
            m[A[i]]--;

            ll aux = 0;
            repx(j, i + 1, N)
            {
                m[A[j]]--;
                aux -= s[A[j]];
                if (j > i + 1)
                {
                    s[A[j - 1]]++;
                    aux += m[A[j - 1]];
                }
                if (A[i] == A[j]) ans += aux;
            }
            repx(j, i + 1, N) m[A[j]]++;
        }

        cout << ans << '\n';
    }
}