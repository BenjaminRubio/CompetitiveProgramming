#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int X, N, P, D, U;

void search(int i, int j)
{
    if (i == j) return;

    int m = (i + j) / 2;
    if (m <= P) D += (m < P), search(m + 1, j);
    else U++, search(i, m);
}

const ll MOD = 1e9 + 7;

int main()
{
    cin >> N >> X >> P;

    search(0, N);

    if (X - 1 >= D && N - X >= U)
    {
        ll ans = 1;
        rep(k, D) ans = (ans * (X - 1 - k)) % MOD;
        rep(k, U) ans = (ans * (N - X - k)) % MOD;
        rep(k, N - 1 - D - U) ans = (ans * (k + 1)) % MOD;

        cout << ans << '\n';
    }
    else cout << 0 << '\n';
}