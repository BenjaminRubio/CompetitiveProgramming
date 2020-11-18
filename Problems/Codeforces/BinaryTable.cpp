#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, M, C[110][110]; char x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        rep(i, N) rep(j, M) { cin >> x; C[i][j] = (x == '1'); }

        int ans = 0;
        vector<pair<int, int>> v;
        rep(i, N - 2) rep(j, M - 2) if (C[i][j])
        {
            ans++;
            v.emplace_back(i, j); C[i][j] ^= 1;
            v.emplace_back(i + 1, j); C[i + 1][j] ^= 1;
            v.emplace_back(i, j + 1); C[i][j + 1] ^= 1;
        }

        rep(i, N - 2)
        {
            if (C[i][M - 2] && !C[i][M - 1])
            {
                ans++;
                v.emplace_back(i, M - 2); C[i][M - 2] ^= 1;
                v.emplace_back(i + 1, M - 2); C[i + 1][M - 2] ^= 1;
                v.emplace_back(i + 1, M - 1); C[i + 1][M - 1] ^= 1;
            }
            else if (!C[i][M - 2] && C[i][M - 1])
            {
                ans++;
                v.emplace_back(i, M - 1); C[i][M - 1] ^= 1;
                v.emplace_back(i + 1, M - 2); C[i + 1][M - 2] ^= 1;
                v.emplace_back(i + 1, M - 1); C[i + 1][M - 1] ^= 1;
            }
            else if (C[i][M - 2] && C[i][M - 1])
            {
                ans++;
                v.emplace_back(i, M - 1); C[i][M - 1] ^= 1;
                v.emplace_back(i, M - 2); C[i][M - 2] ^= 1;
                v.emplace_back(i + 1, M - 2); C[i + 1][M - 2] ^= 1;
            }
        }

        rep(j, M - 2)
        {
            if (C[N - 2][j] && !C[N - 1][j])
            {
                ans++;
                v.emplace_back(N - 2, j); C[N - 2][j] ^= 1;
                v.emplace_back(N - 2, j + 1); C[N - 2][j + 1] ^= 1;
                v.emplace_back(N - 1, j + 1); C[N - 1][j + 1] ^= 1;
            }
            else if (!C[N - 2][j] && C[N - 1][j])
            {
                ans++;
                v.emplace_back(N - 1, j); C[N - 1][j] ^= 1;
                v.emplace_back(N - 2, j + 1); C[N - 2][j + 1] ^= 1;
                v.emplace_back(N - 1, j + 1); C[N - 1][j + 1] ^= 1;
            }
            else if (C[N - 2][j] && C[N - 1][j])
            {
                ans++;
                v.emplace_back(N - 1, j); C[N - 1][j] ^= 1;
                v.emplace_back(N - 2, j); C[N - 2][j] ^= 1;
                v.emplace_back(N - 2, j + 1); C[N - 2][j + 1] ^= 1;
            }
        }

        int cnt = 0; vector<pair<int, int>> lon, loff;
        if (C[N - 2][M - 2]) cnt++, lon.emplace_back(N - 2, M - 2);
        else loff.emplace_back(N - 2, M - 2);
        if (C[N - 1][M - 2]) cnt++, lon.emplace_back(N - 1, M - 2);
        else loff.emplace_back(N - 1, M - 2);
        if (C[N - 2][M - 1]) cnt++, lon.emplace_back(N - 2, M - 1);
        else loff.emplace_back(N - 2, M - 1);
        if (C[N - 1][M - 1]) cnt++, lon.emplace_back(N - 1, M - 1);
        else loff.emplace_back(N - 1, M - 1);

        if (cnt == 1)
        {
            ans += 3;
            v.push_back(lon[0]); v.push_back(loff[0]); v.push_back(loff[1]);
            v.push_back(loff[0]); v.push_back(lon[0]); v.push_back(loff[2]);
            v.push_back(lon[0]); v.push_back(loff[1]); v.push_back(loff[2]);
        }
        if (cnt == 2)
        {
            ans += 2;
            v.push_back(lon[0]); v.push_back(loff[0]); v.push_back(loff[1]);
            v.push_back(lon[1]); v.push_back(loff[0]); v.push_back(loff[1]);
        }
        if (cnt == 3)
        {
            ans += 1;
            v.push_back(lon[0]); v.push_back(lon[1]); v.push_back(lon[2]);
        }
        if (cnt == 4)
        {
            ans += 4;
            v.push_back(lon[0]); v.push_back(lon[1]); v.push_back(lon[2]);
            v.push_back(lon[3]); v.push_back(lon[0]); v.push_back(lon[1]);
            v.push_back(lon[0]); v.push_back(lon[3]); v.push_back(lon[2]);
            v.push_back(lon[3]); v.push_back(lon[1]); v.push_back(lon[2]);
        }

        cout << ans << '\n'; int i = 0;
        while (i < 3 * ans)
        {
            cout << v[i].ff + 1 << ' ' << v[i++].ss + 1 << ' ';
            cout << v[i].ff + 1 << ' ' << v[i++].ss + 1 << ' ';
            cout << v[i].ff + 1 << ' ' << v[i++].ss + 1 << ' ';
            cout << '\n';
        }
    }
}