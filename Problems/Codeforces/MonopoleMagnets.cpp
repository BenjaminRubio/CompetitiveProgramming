#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

char aux;
int n, m;
bool M[1001][1001], C[1001][1001], V[1001][1001];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int i, int j)
{
    V[i][j] = 1;
    rep(k, 4)
    {
        int i_ = i + di[k], j_ = j + dj[k];
        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && M[i][j] && !V[i_][j_]) dfs(i_, j_);
    }
}

int main()
{
    cin >> n >> m;

    memset(M, 0, sizeof M);
    memset(C, 0, sizeof C);
    rep(i, n) rep(j, m)
    {
        cin >> aux;
        M[i][j] = (aux == '#');
    }

    rep(i, n) rep(j, m) if (M[i][j])
    {
        int ad = 0;

        rep(k, 4)
        {
            int i_ = i + di[k], j_ = j + dj[k];
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && M[i_][j_]) ad++;
        }

        if (ad <= 2) C[i][j] = 1;
    }

    bool pos = true;
    bool blank_i = 0, blank_j = 0;
    rep(i, n)
    {
        bool b = 0, c = 0, w = 0;
        rep(j, m)
        {
            if (M[i][j] == 1) b = 1;
            if (C[i][j] == 1) c = 1;
            if (M[i][j] == 0 && c) w = 1;
            if (M[i][j] == 1 && w) pos = false;
        }
        if (!b) blank_i = 1;
    }

    rep(j, m)
    {
        bool b = 0, c = 0, w = 0;
        rep(i, n)
        {
            if (M[i][j] == 1) b = 1;
            if (C[i][j] == 1) c = 1;
            if (M[i][j] == 0 && c) w = 1;
            if (M[i][j] == 1 && w) pos = false;
        }
        if (!b) blank_j = 1;
    }

    if (blank_i ^ blank_j) pos = false;

    if (pos)
    {
        int ans = 0;
        memset(V, 0, sizeof V);
        rep(i, n) rep(j, m) if (M[i][j] && !V[i][j]) { dfs(i, j); ans++; }
        cout << ans << '\n';
    }
    else cout << -1 << '\n';
}