#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MAXN = 100;
const ll INF = 2e18;

struct Matrix
{
    ll m[MAXN][MAXN];
    Matrix operator*(const Matrix &o)
    {
        Matrix ans;
        rep(i, MAXN) rep(j, MAXN) ans.m[i][j] = INF;
        rep(i, MAXN) rep(j, MAXN) rep(k, MAXN)
            ans.m[i][k] = min(ans.m[i][k], m[i][j] + o.m[j][k]);
        return ans;
    }
};

int N, M, K, a, b, c;

int main()
{
    cin >> N >> M >> K;

    Matrix ans, A;
    rep(i, MAXN) rep(j, MAXN) ans.m[i][j] = A.m[i][j] = INF;
    rep(i, MAXN) ans.m[i][i] = 0;

    rep(_, M)
    {
        cin >> a >> b >> c; a--, b--;
        A.m[a][b] = c;
    }

    while (K)
    {
        if (K & 1) ans = ans * A;
        A = A * A, K >>= 1;
    }

    ll C = INF;
    rep(i, N) rep(j, N) C = min(C, ans.m[i][j]);

    if (C <= 1e18) cout << C << '\n';
    else cout << "IMPOSSIBLE\n";
}