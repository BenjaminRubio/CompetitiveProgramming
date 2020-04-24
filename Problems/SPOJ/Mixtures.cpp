#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef long long ll;

int n, c;
vector<int> s;
ll DP[110][110];

inline ll cl(int l, int r) { return (s[r] - s[l - 1]) % 100ll; }

ll dp(int l, int r)
{
    if (l == r) return 0;
    if (DP[l][r] != -1) return DP[l][r];

    ll ans = LLONG_MAX;
    repx(i, l, r) ans = min(ans, cl(l, i) * cl(i + 1, r) + 
                                 dp(l, i) + dp(i + 1, r));
    return DP[l][r] = ans;
}

int main()
{
    while (cin >> n)
    {
        s.resize(n + 1); s[0] = 0;
        rep(i, n)
        {
            cin >> c;
            s[i + 1] = s[i] + c;
        }

        memset(DP, -1, sizeof DP);
        cout << dp(1, n) << '\n';
    }
}