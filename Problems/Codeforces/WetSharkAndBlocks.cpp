#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MAXN = 100, MOD = 1e9 + 7;

ll N, B, K, X, P[32], A;

struct Matrix
{
    ll m[MAXN][MAXN] = {0};
    Matrix operator*(const Matrix &o) const
    {
        Matrix ans;
        rep(i, X) rep(j, X) rep(k, X)
            ans.m[i][k] = (ans.m[i][k] + m[i][j] * o.m[j][k]) % MOD;
        return ans;
    }
};

int main()
{
    cin >> N >> B >> K >> X;

    Matrix M;
    rep(i, N)
    {
        cin >> A;
        rep(i, X) M.m[i][(10 * i + A) % X]++;
    }

    Matrix ans; ans.m[0][0] = 1;
    while (B)
    {
        if (B & 1ll) ans = ans * M;
        M = M * M, B >>= 1ll;
    }

    cout << ans.m[0][K] << '\n';
}