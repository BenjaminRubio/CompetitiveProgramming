#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct RH
{
    int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vector<int> H[2], I[2];
    RH() {}
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
    ll get(int l, int r)
    {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][r] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};

int T, N;
string s; RH h;

struct Pos
{
    int i; Pos(int i) : i(i) {}
    bool operator>(const Pos &p) const
    {
        int l = 0, r = N;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (h.get(i, i + m + 1) != h.get(p.i, p.i + m + 1)) r = m;
            else l = m + 1;
        }
        return l < N ? s[i + l] > s[p.i + l] : i > p.i;
    }
};

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s; N = s.size();
        s += s; h = RH(s);
        
        Pos p(0);
        rep(i, N) if (p > Pos(i)) p = Pos(i);

        cout << p.i + 1 << '\n';
    }
}