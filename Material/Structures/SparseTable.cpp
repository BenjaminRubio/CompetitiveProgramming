#include "../Template.cpp"

struct OP
{
    static const int neutro = 0;
    static int merge(int x, int y) { return x + y; }
};

template <class t>
class ST
{
    int N; vi DP;

public:
    ST(vi &v)
    {
        N = sz(v); int LOG = 31 - __builtin_clz(n);
        DP.assign(N * (LOG + 1), -1);
        rep(i, N) DP[i] = v[i];
        rep(k, LOG) rep(i, N)
            DP[(k + 1) * N + i] = t::merge(DP[k * N + i], 
                                           DP[k * N + i + (1 << k)]);
    }
    int query_O1(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return t::merge(DP[k * N + l], DP[k * N + r - (1 << k) + 1]);
    }
    int query_Ologn(int l, int r)
    {
        int ans = t::neutro;
        int d = r - l + 1;
        for (int k = 0; d; k++, k >>= 1) if (k & 1)
            ans = t::merge(ans, DP[k * N + l]), l += 1 << e;
        return ans;
    }
};
