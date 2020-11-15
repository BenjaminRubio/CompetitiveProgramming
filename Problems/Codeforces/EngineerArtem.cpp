#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
vector<vector<bool>> V;
vector<vector<int>> G;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void dfs(int r, int c, int f)
{
    V[r][c] = 1; G[r][c] += f;
    rep(k, 4)
    {
        int r_ = r + dr[k], c_ = c + dc[k];
        if (r_ >= 0 && r_ < N && c_ >= 0 && c_ < M && !V[r_][c_])
        {
            if (G[r][c] == G[r_][c_]) dfs(r_, c_, 1);
            if (G[r][c] == G[r_][c_] + 1) dfs(r_, c_, 0);
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        G.assign(N, vector<int>(M));
        rep(i, N) rep(j, M) cin >> G[i][j];

        V.assign(N, vector<bool>(M, 0));
        rep(i, N) rep(j, M) if (!V[i][j]) dfs(i, j, 0);

        rep(i, N)
        {
            rep(j, M) cout << G[i][j] << ' ';
            cout << '\n';
        }
    }
}