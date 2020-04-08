#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m;
vector<vector<char>> ans;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        ans.assign(n, vector<char>(m));
        rep(i, n) rep(j, m) ans[i][j] = (((i + j) % 2) ? 'W' : 'B');
        if ((n * m) % 2 == 0) ans[0][1] = 'B';

        rep(i, n)
        {
            rep(j, m) cout << ans[i][j];
            cout << '\n';
        }
    }
}