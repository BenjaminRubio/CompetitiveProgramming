#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        ll prev = LLONG_MIN, a, ans = 0;
        rep(i, n)
        {
            cin >> a;
            if (a < prev)
            {
                ll dif = prev - a, b = 0;
                while ((1ll << b) <= dif) b++;
                ans = max(ans, b);
            }
            else prev = a;
        }
        cout << ans << '\n';
    }
}