#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, p, k;
vector<int> a;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> p >> k;

        a.resize(n);
        rep(i, n) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        int o = 0;
        rep(i, n - n / 2)
        {
            o += a[2 * i];
            if (o <= p)
                ans = max(ans, 2 * i  + 1);
            else
                break;
        }
        int e = 0;
        rep(i, n / 2)
        {
            e += a[2 * i + 1];
            if (e <= p)
                ans = max(ans, 2 * i + 2);
            else
                break;
        }

        cout << ans << '\n';
    }
}