#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M;
vector<int> P;

ll calc(int x)
{
    ll ans = 0;
    for (int i = 0; i < x; i += M) ans += 2ll * (P[x] - P[i]);
    for (int i = N - 1; i >= x; i -= M) ans += 2ll * (P[i] - P[x]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    P.resize(N);
    rep(i, N) cin >> P[i];

    int l = 0, r = N - 1;
    while (r - l > 10)
    {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;

        ll f1 = calc(m1), f2 = calc(m2);

        if (f1 >= f2) l = m1;
        if (f2 >= f1) r = m2;
    }
    ll ans = calc(l);
    for (int k = l; k <= r; k++) ans = min(ans, calc(k));
    cout << ans << '\n';
}