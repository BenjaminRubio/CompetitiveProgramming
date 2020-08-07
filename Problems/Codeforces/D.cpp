#pragma "Ofast"
#pragma "unroll-loops"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M;
vector<vector<char>> T;
vector<vector<int>> P;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    T.assign(N, vector<char>(M));
    rep(i, N) rep(j, M) cin >> T[i][j];

    P.assign(N, vector<int>(M, 0));
    queue<pair<int, pair<int, int>>> q;
    rep(i, N) rep(j, M) q.emplace(1, make_pair(i, j));
    int ans = N * M;
    while (!q.empty())
    {
        auto e = q.front(); q.pop(); int i = e.ss.ff, j = e.ss.ss;
        if (i >= e.ff && j >= e.ff && (N - i - 1 >= e.ff) && (M - j - 1 >= e.ff))
        {
            char t = T[i][j];
            if (t == T[i + 1][j] && t == T[i - 1][j] && t == T[i][j + 1] && t == T[i][j - 1])
            {
                if ((P[i + 1][j] >= e.ff - 1) && (P[i - 1][j] >= e.ff - 1) && (P[i][j + 1] >= e.ff - 1) && (P[i][j - 1] >= e.ff - 1))
                {
                    P[i][j]++, ans++;
                    q.emplace(e.ff + 1, make_pair(i, j));
                }
            }
        }
    }

    cout << ans << '\n';
}