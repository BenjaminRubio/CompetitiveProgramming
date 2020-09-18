#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, K;
ld p, P[10001][52];

ld bin_pow(ld a, int p)
{
    ld ans = 1, b = a;
    while (p)
    {
        if (p & 1) ans *= b;
        b *= b, p >>= 1;
    }
    return ans;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> K >> p;

    memset(P, 0, sizeof P); P[0][K] = 1;
    repx(i, 1, 10001) rep(j, K + 1)
        P[i][j] = P[i - 1][j] * (j ? p : 1.) + P[i - 1][j + 1] * (1 - p);

    ld ans = 0;
    rep(i, 10000) ans += (P[i + 1][0] - P[i][0]) * bin_pow(P[i][0], N - 1);

    cout << 1 - ld (N) * ans << '\n';
}