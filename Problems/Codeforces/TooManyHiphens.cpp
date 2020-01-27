#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll K;
int L, R;
string s, s_;
ll DP[100][100][100];

ll dp(int i, int l, int r)
{
    if (l < 0 or r < 0 or l > r) return 0;
    if (i == s.size() and l == 0 and r <= 1) return 1;
    if (i == s.size()) return 0;

    if (DP[i][l][r] != -1LL)
        return DP[i][l][r];

    ll ans = 0;
    if (!(i > 0 and s[i] == '-' and s[i - 1] == '-'))
        ans += dp(i + 1, l, r);
    ans += dp(i + 1, l - 1, r);
    ans += dp(i + 1, l, r - 1);
    ans += dp(i + 1, l - 2, r);
    ans += dp(i + 1, l, r - 2);
    ans += dp(i + 1, l - 1, r - 1);
    if (l != r) ans += dp(i + 1, l - 1, r - 1);
    
    return DP[i][l][r] = ans;
}

int main()
{
    cin >> s >> K;
    s_ = "";

    memset(DP, -1LL, sizeof DP);

    int c = 0;
    rep(i, s.size() - 1)
        if (s[i] == '-' and s[i + 1] == '-')
            c++;

    L = R = c - c / 2;

    if (K > dp(0, L, R))
    {
        cout << "Overflow\n";
        return 0;
    }

    ll C = 0, aux;
    rep(i, s.size())
    {
        if (s[i] == '+')
        {
            aux = dp(i + 1, L, R);
            if (C + aux >= K)
            {
                s_ += '+';
                continue;
            }
            C += aux;
            if (L)
            {
                aux = dp(i + 1, L - 1, R);
                if (C + aux >= K)
                {
                    s_ += "{+"; L--;
                    continue;
                }
                C += aux;
            }
            if (R > L)
            {
                aux = dp(i + 1, L, R - 1);
                if (C + aux >= K)
                {
                    s_ += "}+"; R--;
                    continue;
                }
                C += aux;
            }
        }
        else if (s[i] == '-')
        {
            if (!(i > 0 and s[i - 1] == '-'))
            {
                aux = dp(i + 1, L, R);
                if (C + aux >= K)
                {
                    s_ += '-';
                    continue;
                }
                C += aux;
            }
            if (L)
            {
                aux = dp(i + 1, L - 1, R);
                if (C + aux >= K)
                {
                    s_ += "{-"; L--;
                    continue;
                }
                C += aux;
            }
            if (L > 1)
            {
                aux = dp(i + 1, L - 2, R);
                if (C + aux >= K)
                {
                    s_ += "{{-"; L -= 2;
                    continue;
                }
                C += aux;
            }
            if (L and R)
            {
                aux = dp(i + 1, L - 1, R - 1);
                if (C + aux >= K)
                {
                    s_ += "{}-"; R--; L--;
                    continue;
                }
                C += aux;
            }
            if (R > L)
            {
                aux = dp(i + 1, L, R - 1);
                if (C + aux >= K)
                {
                    s_ += "}-"; R--;
                    continue;
                }
                C += aux;
            }
            if (L and R)
            {
                aux = dp(i + 1, L - 1, R - 1);
                if (R > L and C + aux >= K)
                {
                    s_ += "}{-"; R--; L--;
                    continue;
                }
                C += aux;
            }
            if (R > L + 1)
            {
                aux = dp(i + 1, L, R - 2);
                if (C + aux >= K)
                {
                    s_ += "}}-"; R -= 2;
                    continue;
                }
                C += aux;
            }
        }
    }

    if (R)
    {
        s_ += '}';
        R--;
    }

    cout << s_ << '\n';
}
