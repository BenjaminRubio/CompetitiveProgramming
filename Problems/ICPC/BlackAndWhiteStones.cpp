#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef long long ll;

ll A, B;
string s;

int main()
{
    while (cin >> A >> B >> s)
    {
        int b = 0;
        rep(i, s.size()) if (s[i] == 'B') b++;

        ll ans = LLONG_MAX;
        rep(i, b + 1)
        {
            ll m = (ll)i * A;
            int ind = i;
            rep(j, s.size()) if (s[j] == 'B' && ind < b && j > ind++)
                m += (A - B) * (ll)(j - (ind - 1));

            ans = min(ans, m);
        }

        cout << ans << '\n';
    }
}