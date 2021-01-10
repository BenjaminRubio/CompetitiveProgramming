#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int a, b, c;
vector<ll> A[3];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> c;

    ll s[3] = {0, 0, 0};
    A[0].resize(a); rep(i, a) { cin >> A[0][i]; s[0] += A[0][i]; }
    A[1].resize(b); rep(i, b) { cin >> A[1][i]; s[1] += A[1][i]; }
    A[2].resize(c); rep(i, c) { cin >> A[2][i]; s[2] += A[2][i]; }

    sort(A[0].begin(), A[0].end());
    sort(A[1].begin(), A[1].end());
    sort(A[2].begin(), A[2].end());

    ll ans = 0, ss = s[0] + s[1] + s[2];
    rep(i, 3) rep(j, 3) if (i != j)
    {
        ans = max(ans, ss - 2ll * A[i][0] - 2ll * A[j][0]);
        ans = max(ans, ss - 2ll * s[j]);
        ans = max(ans, ss - 2ll * s[i]);
    }

    cout << ans << '\n';
}