#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, R, C, K;
vector<vector<int>> m;
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

void simulate()
{
    vector<vector<int>> M(R, vector<int>(C, 0));
    rep(i, R) rep(j, C) M[i][j] = m[i][j];

    rep(i, R) rep(j, C) rep(k, 4)
    {
        int i_ = i + dx[k], j_ = j + dy[k];
        if (i_ >= 0 && i_ < R && j_ >= 0 && j_ < C && m[i_][j_] == (m[i][j] + 1) % N)
            M[i_][j_] = m[i][j];
    }

    swap(m, M);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N >> R >> C >> K)
    {
        if (N == 0)
            break;

        m.assign(R, vector<int>(C, 0));
        rep(i, R) rep(j, C) cin >> m[i][j];

        rep(k, K) simulate();

        rep(i, R)
        {
            rep(j, C - 1) cout << m[i][j] << ' ';
            cout << m[i][C - 1] << '\n';
        }
    }
}