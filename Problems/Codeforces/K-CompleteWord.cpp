#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, k;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        cin >> s;

        vector<vector<int>> v(k, vector<int>(26, 0));
        rep(i, n / k) rep(j, k) v[j][s[i * k + j] - 'a']++;
        
        int ans = 0;
        rep(i, k / 2)
        {
            int M = -1;
            rep(j, 26) M = max(M, v[i][j] + v[k - i - 1][j]);

            ans += 2 * (n / k) - M;
        }
        if (k % 2)
        {
            int M = -1;
            rep(j, 26) M = max(M, v[k / 2][j]);

            ans += (n / k) - M;
        }

        cout << ans << '\n';
    }
}