#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int INF = 1e9;

int n, m, q, u, v, w;
vector<vector<int>> D;

void floydWarshall ()
{
    rep(k, n) rep(i, n) rep(j, n) if (D[i][k] < INF && D[k][j] < INF)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    rep(k, n) rep(i, n) rep(j, n) if (D[i][k] < INF && D[k][j] < INF && 
                                      D[k][k] < 0)
        D[i][j] = -INF;
}

int main()
{
    while (cin >> n >> m >> q)
    {
        if (n == 0) break;

        D.assign(n, vector<int>(n, INF));
        rep(i, n) D[i][i] = 0;
        rep(_, m)
        {
            cin >> u >> v >> w;
            D[u][v] = min(D[u][v], w);
        }

        floydWarshall();

        rep(_, q)
        {
            cin >> u >> v;
            if (D[u][v] == INF) cout << "Impossible\n";
            else if (D[u][v] == -INF) cout << "-Infinity\n";
            else cout << D[u][v] << '\n';
        }
        cout << '\n';
    }
}