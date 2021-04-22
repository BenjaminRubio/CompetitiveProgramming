#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q; ll l, r;
vector<ll> S, D, acc;

int main()
{
    cin >> N;

    S.resize(N); rep(i, N) cin >> S[i];

    sort(S.begin(), S.end());

    D.resize(N - 1);
    rep(i, N - 1) D[i] = S[i + 1] - S[i];

    sort(D.begin(), D.end());

    acc = D;
    rep(i, N - 2) acc[i + 1] = acc[i + 1] + acc[i];

    cin >> Q;
    while (Q--)
    {
        cin >> l >> r; r = r - l + 1;
        
        int p = lower_bound(D.begin(), D.end(), r) - D.begin();

        ll ans = r * (N - p) + (p ? acc[p - 1] : 0);
        cout << ans << ' ';
    }
    cout << '\n';
}