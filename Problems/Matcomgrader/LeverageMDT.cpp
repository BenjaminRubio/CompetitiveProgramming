#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ff first
#define ss second

int N, M;
vector<vector<char>> m;
vector<vector<int>> c;

int main()
{
    cin >> N >> M;

    m.assign(N, vector<char>(M, '.'));
    rep(i, N) rep(j, M) cin >> m[i][j];

    c.assign(N, vector<int>(M, 0));
    rep(i, N)
    {
        int aux = 0;
        char last = '.';
        rep_(j, M)
        {
            if (m[i][j] == last) c[i][j] = aux + 1;
            else { c[i][j] = 1; aux = 0; }
            aux++; last = m[i][j];
        }
    }

    int ans = 0;
    rep(j, M)
    {
        vector<int> l(N, 0), r(N, 0);
        stack<pair<int, int>> sl, sr;
        sl.push({-1, -1}); sr.push({-1, N});
        rep(i, N)
        {
            while (sl.top().ff >= c[i][j]) sl.pop();
            l[i] = sl.top().ss;
            sl.push({c[i][j], i});
        }
        rep_(i, N)
        {
            while (sr.top().ff >= c[i][j]) sr.pop();
            r[i] = sr.top().ss;
            sr.push({c[i][j], i});
        }
        rep(i, N) ans = max(ans, min(r[i] - l[i] - 1, c[i][j]));
    }

    cout << ans * ans << '\n';
}