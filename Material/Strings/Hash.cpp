#include "../Template.cpp"

struct RH
{
    int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vi H[2], I[2];
    RH(string &s)
    {
        int N = s.size(); rep(k, 2)
        {
            H[k].resize(N + 1), I[k].resize(N + 1);
            H[k][0] = 0, I[k][0] = 1; ll b = 1;
            rep(i, N + 1) if (i)
            {
                H[k][i] = (H[k][i - 1] + b * s[i - 1]) % M[k];
                I[k][i] = (1LL * I[k][i - 1] * P[k]) % M[k];
                b = (b * B) % M[k];
            }
        }
    }
    ll get(int l, int r)  // inclusive - exclusive
    {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][l] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};


// dynamic version

struct RH
{
    static const int MAXN = 1000000, B = 1777771, M0 = 999727999, 
        M1 = 1070777777, P0 = 325255434, P1 = 10018302;
    static int H[2][MAXN], I[2][MAXN]; static ll BB[2][MAXN];
    int l = 1;
    static void init()
    {
        rep(k, 2) H[k][0] = 0, I[k][0] = 1, BB[k][0] = 1;
        rep(i, MAXN + 1) if (i)
        {
            BB[0][i] = (BB[0][i - 1] * B) % M0, BB[1][i] = (BB[1][i - 1] * B) % M1;
            I[0][i] = (1LL * I[0][i - 1] * P0) % M0, I[1][i] = (1LL * I[1][i - 1] * P1) % M1;
        }
    }
    RH(string &s) { for (char c : s) add(c); }
    void add(char c)
    {
        H[0][l] = (H[0][l - 1] + BB[0][l - 1] * c) % M0;
        H[1][l] = (H[1][l - 1] + BB[1][l - 1] * c) % M1;
        l++;
    }
    void pop() { l--; }
    ll get(int a, int b)  // inclusive - exclusive
    {
        ll h0 = (H[0][b] - H[0][a] + M0) % M0;
        h0 = (1LL * h0 * I[0][a]) % M0;
        ll h1 = (H[1][b] - H[1][a] + M1) % M1;
        h1 = (1LL * h1 * I[1][a]) % M1;
        return (h0 << 32) | h1;
    }
};
