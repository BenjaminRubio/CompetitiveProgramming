#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int R, C;
vector<vector<int>> m;
vector<vector<bool>> v;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void dfs(int r, int c)
{
    if (v[r][c]) return;
    v[r][c] = 1;

    rep(k, 4)
    {
        int r_ = r + dr[k];
        int c_ = c + dc[k];

        if (r_ >= 0 and c >= 0 and r_ < R and c_ < C and m[r][c] == m[r_][c_])
            dfs(r_, c_);
    }
}

int main()
{
    while (cin >> R >> C)
    {
        m.assign(R, vector<int>(C, 0));
        rep(i, R) rep(j, C) cin >> m[i][j];

        int ans = 5;

        rep(i, R - 1)
        {
            int last1 = INT_MAX, last2 = -1;
            bool face = false;
            rep(j, C)
            {
                if (m[i][j] <= m[i + 1][j] or (face and (m[i + 1][j] >= last1 or m[i][j] <= last2)))
                {
                    ans += face;
                    face = (m[i][j] > m[i + 1][j]);
                }
                else face = true;
                last1 = m[i][j], last2 = m[i + 1][j];
            }
            ans += face;
        }

        rep(i, R - 1)
        {
            int last1 = INT_MAX, last2 = -1;
            bool face = false;
            rep(j, C)
            {
                if (m[R - i - 1][j] <= m[R - i - 2][j] or (face and (m[R - i - 2][j] >= last1 or m[R - i - 1][j] <= last2)))
                {
                    ans += face;
                    face = (m[R - i - 1][j] > m[R - i - 2][j]);
                }
                else face = true;
                last1 = m[R - i - 1][j], last2 = m[R - i - 2][j];
            }
            ans += face;
        }

        rep(i, C - 1)
        {
            int last1 = INT_MAX, last2 = -1;
            bool face = false;
            rep(j, R)
            {
                if (m[j][i] <= m[j][i + 1] or (face and (m[j][i + 1] >= last1 or m[j][i] <= last2)))
                {
                    ans += face;
                    face = (m[j][i] > m[j][i + 1]);
                }
                else face = true;
                last1 = m[j][i], last2 = m[j][i + 1];
            }
            ans += face;
        }

        rep(i, C - 1)
        {
            int last1 = INT_MAX, last2 = -1;
            bool face = false;
            rep(j, R)
            {
                if (m[j][C - i - 1] <= m[j][C - i - 2] or (face and (m[j][C - i - 2] >= last1 or m[j][C - i - 1] <= last2)))
                {
                    ans += face;
                    face = (m[j][C - i - 1] > m[j][C - i - 2]);
                }
                else face = true;
                last1 = m[j][C - i - 1], last2 = m[j][C - i - 2];
            }
            ans += face;
        }

        v.assign(R, vector<bool>(C, 0));
        rep(i, R) rep(j, C) if (!v[i][j]) { dfs(i, j); ans++; }

        cout << ans << '\n';
    }
}