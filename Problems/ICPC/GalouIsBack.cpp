#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int R, C;
vector<vector<char>> M;
vector<vector<int>> rot;
int dr[6] = {- 1, -1, 0, 0, 1, 1};
int dc[6] = {0, 1, -1, 1, -1, 0}; 

bool dfs(int r, int c, int p)
{
    rot[r][c] = p;
    bool ans = false;
    rep(k, 6)
    {
        int r_ = r + dr[k], c_ = c + dc[k];
        if (r_ >= 0 and r_ < R and c_ >= 0 and c_ < C and M[r_][c_] != '.')
        {
            if (rot[r_][c_] == p) return true;
            if (rot[r_][c_] == -1) ans |= dfs(r_, c_, (p == 1) ? 2 : 1);
        }
    }
    return ans;
}

void block(int r, int c)
{
    rot[r][c] = 0;
    rep(k, 6)
    {
        int r_ = r + dr[k], c_ = c + dc[k];
        if (r_ >= 0 and r_ < R and c_ >= 0 and c_ < C and 
            M[r_][c_] != '.' and rot[r_][c_])
            block(r_, c_);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> R >> C)
    {
        if (R == 0 and C == 0) break;

        M.assign(R, vector<char>(C));
        rep(i, R) rep(j, C) cin >> M[i][j];

        rot.assign(R, vector<int>(C, -1));

        rep(i, R) rep(j, C)
        {
            if (M[i][j] == 'I' and rot[i][j])
            {
                if (rot[i][j] == 1) continue;
                if (rot[i][j] == 2) block(i, j);
                else if (dfs(i, j, 1)) block(i, j);
            }
        }

        cout << '\n';
        rep(i, R)
        {
            rep(j, C) if (M[i][j] != '.')
            {
                if (rot[i][j] == -1) cout << 'F';
                if (rot[i][j] == 0) cout << 'B';
                if (rot[i][j] == 1) cout << '(';
                if (rot[i][j] == 2) cout << ')';
            } else cout << '.';
            cout << '\n';
        }
    }
}