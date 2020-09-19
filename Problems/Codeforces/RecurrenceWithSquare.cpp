#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

const ll MOD = 1e9 + 7;

struct Matrix
{
    ll m[13][13] = {0};
    Matrix operator*(const Matrix &o)
    {
        Matrix ans;
        rep(i, 13) rep(j, 13) rep(k, 13)
            ans.m[i][k] = (ans.m[i][k] + m[i][j] * o.m[j][k]) % MOD;
        return ans;
    }
};

ll N, K, p, q, r;
vector<ll> A, C;

int main()
{
    cin >> N >> K;

    A.resize(N);
    rep(i, N) cin >> A[i];

    C.resize(N);
    rep(i, N) cin >> C[i];

    cin >> p >> q >> r;

    Matrix ans, B;
    rep(i, N) ans.m[0][i] = A[i];
    ans.m[0][10] = N, ans.m[0][11] = N * N, ans.m[0][12] = 1;

    repx(i, 1, N) B.m[i][i - 1] = 1;
    rep(i, N) B.m[i][N - 1] = C[N - i - 1];
    B.m[10][N - 1] = q, B.m[11][N - 1] = r, B.m[12][N - 1] = p;
    B.m[10][10] = 1, B.m[11][11] = 1, B.m[12][12] = 1;
    B.m[12][10] = 1, B.m[12][11] = 1, B.m[10][11] = 2;

    while (K)
    {
        if (K & 1ll) ans = ans * B;
        B = B * B, K >>= 1ll;
    }

    cout << ans.m[0][0] << '\n';
}