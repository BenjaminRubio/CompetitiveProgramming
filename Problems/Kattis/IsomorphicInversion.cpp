#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct RH
{
    int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vector<int> H[2], I[2];
    RH(string& s)
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
    ll get(int l, int r)
    {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][r] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};

int N;
string S;

int main()
{
    cin >> S; N = S.size(); bool p = N % 2;

    RH rh(S);

    int ans = 0, i = 0, j = 0;
    while (j < N / 2)
    {
        if (rh.get(i, j + 1) == rh.get(N - j - 1, N - i)) ans += 2, i = ++j;
        else if (j++ == N / 2 - 1) ans++, p = 0;
    }

    if (p) ans++;
    cout << ans << '\n';
}