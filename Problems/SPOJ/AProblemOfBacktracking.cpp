#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, K, A[10], N[10];
bool D[10];

bool backtrack(ll i, ll s)
{
    if (s > K) return false;
    if (i == 10 && s == K) return true;

    rep(d, 10) if (!D[d])
    {
        D[d] = 1, A[i] = d;
        if (backtrack(i + 1, s + N[i] * d)) return true;
        D[d] = 0;
    }
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        rep(i, 10) cin >> N[i];
        cin >> K;

        memset(D, 0, sizeof D);

        if (backtrack(0, 0))
        {
            rep(i, 10) cout << A[i] << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
}