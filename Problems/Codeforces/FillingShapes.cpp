#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

int main()
{
    cin >> N;
    if (N & 1) { cout << 0 << '\n'; return 0; }

    ll ans = 1;
    rep(_, N / 2) ans *= 2;

    cout << ans << '\n';
}
