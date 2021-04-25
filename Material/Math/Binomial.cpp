#include <Euclid.cpp>
#include <Modular.cpp>

const ll MOD = 1e9 + 7;
const int MAXN = 1000;

// DP bottom-up
ll C[MAXN + 1][MAXN + 1];
void init_C()
{
    rep(m, MAXN + 1) if (m)
    {
        C[m][0] = C[m][m] = 1;
        rep(k, m) if (k) C[m][k] = add(C[m - 1][k], C[m - 1][k - 1]);
    }
}

// By definition and euclid
ll F[MAXN];
ll choose(int n, int k)
{
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

// Multinomial Coefficient
ll multinomial(vector<int> K)
{
    ll n = 0, ans = 1;
    for (int k : K) n += k, ans = mul(ans, choose(n, k));
    return ans;
}
