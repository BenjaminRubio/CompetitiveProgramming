#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long n, m;
vector<long long> f;

int main()
{
    cin >> n >> m;
    f.resize(n + 1);
    f[0] = 1;
    rep(i, n) f[i + 1] = (((i + 1) * f[i]) % m + m) % m;

    long long ans = 0;
    rep(i, n)
    {
        ans += f[i + 1] * f[n - i - 1] % m * (n - i) % m * (n - i) % m;
        ans %= m;
    }
    cout << ans << '\n';
}