#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

matrix mul(matrix &A, matrix &B)
{
    matrix ans = {{0, 0}, {0, 0}};
    rep(i, 2) rep(j, 2) rep(k, 2) ans[i][k] = (ans[i][k] + A[i][j] * B[j][k]) % MOD;
    return ans;
}

ll N;

int main()
{
    cin >> N; N++;

    matrix A = {{0, 1}, {1, 1}}, ans = {{1, 0}, {0, 1}};
    while (N)
    {
        if (N & 1ll) ans = mul(ans, A);
        A = mul(A, A), N >>= 1ll;
    }

    cout << ans[0][0] << '\n';
}