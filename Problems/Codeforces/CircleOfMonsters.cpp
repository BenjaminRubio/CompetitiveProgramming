#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int T, n;
ll a[300010], b[300010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n;

        rep(i, n) cin >> a[i] >> b[i];

        int id;
        ll aux = LLONG_MAX, ans;
        rep(i, n) if (aux > (a[i] - max(0ll, a[i] - b[(i ? (i - 1) : n - 1)])))
        {
            ans = a[i];
            aux = (a[i] - max(0ll, a[i] - b[(i ? (i - 1) : n - 1)]));
            id = i;
        }
        rep(i, n) if (i != id)
            ans += max(0ll, a[i] - b[(i ? (i - 1) : n - 1)]);

        cout << ans << '\n';
    }
}