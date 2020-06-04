#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
ll N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        ll ans = 0;
        rep(i, 63) if ((1ll << i) & N) ans += (1ll << (i + 1)) - 1ll;

        cout << ans << '\n';
    }
}