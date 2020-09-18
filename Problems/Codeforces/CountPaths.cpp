#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

int n, m, k, a, b;
matrix M;

matrix mul(matrix &A, matrix &B)
{
    matrix ans(n, vector<ll>(n, 0));
    rep(i, n) rep(j, n) rep(k, n) ans[i][k] = (ans[i][k] + A[i][j] * B[j][k]) % MOD;
    return ans;
}

int main()
{
    cin >> n >> m >> k;

    M.resize(n, vector<ll>(n, 0));
    rep(_, m) { cin >> a >> b; a--, b--; M[a][b] = 1; }

    matrix ans(n, vector<ll>(n, 0));
    rep(i, n) ans[i][i] = 1;

    while (k)
    {
        if (k & 1) ans = mul(ans, M);
        M = mul(M, M), k >>= 1;
    }

    ll C = 0;
    rep(i, n) rep(j, n) C = (C + ans[i][j]) % MOD;

    cout << C << '\n';
}