#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

const ll MAXN = 200;
const ll MOD = 1e9 + 7;

struct Matrix
{
    ll m[MAXN][MAXN] = {0};
    Matrix operator*(const Matrix &o) const
    {
        Matrix ans;
        rep(i, MAXN) rep(j, MAXN) rep(k, MAXN)
            ans.m[i][k] = (ans.m[i][k] + m[i][j] * o.m[j][k]) % MOD;
        return ans;
    }

};

int n, m, q, a, b, s, t, k;
Matrix P[31], M, I;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    rep(i, m)
    {
        cin >> a >> b; a--, b--;
        M.m[a][b] = 1;
    }

    rep(i, MAXN) P[0].m[i][i] = 1;
    P[1] = M;
    repx(i, 2, 31) P[i] = P[i - 1] * P[i - 1];
    
    rep(_, q)
    {
        cin >> s >> t >> k; s--, t--;

        ll v[MAXN] = {0}; v[s] = 1;

        rep(i, 30) if (k & (1 << i))
        {
            ll v_[MAXN] = {0};
            rep(j, MAXN) rep(k, MAXN)
                v_[j] = (v_[j] + v[k] * P[i + 1].m[k][j]) % MOD;
            swap(v, v_);
        }

        cout << v[t] << '\n';
    }
}