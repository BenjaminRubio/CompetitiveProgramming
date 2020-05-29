#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m, x, y;
vector<vector<bool>> M;
char ch;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> x >> y;

        M.assign(n, vector<bool>(m, false));
        rep(i, n) rep(j, m)
        {
            cin >> ch;
            M[i][j] = (ch == '.');
        }

        bool p = (y < 2 * x);

        int ans = 0;
        rep(i, n)
        {
            int j = 0;
            while (j < m)
            {
                if (p && j < m - 1 && M[i][j] && M[i][j + 1])
                {
                    ans += y;
                    j++;
                }
                else if (M[i][j]) ans += x;
                j++;
            }
        }

        cout << ans << '\n';
    }
}