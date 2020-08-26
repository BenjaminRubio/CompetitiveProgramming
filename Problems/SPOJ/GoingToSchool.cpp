#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, s, t, u, v, C;
vector<vector<int>> G;
vector<int> S;
vector<vector<ld>> M, M_, M__;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(8);

    cin >> T;
    while (T--)
    {
        cin >> N >> s >> t; s--, t--;

        G.assign(N, vector<int>(N));
        S.assign(N, 0);
        rep(i, N - 1)
        {
            cin >> u >> v >> C; u--, v--;
            G[u][v] = C;
            G[v][u] = C;
            S[u] += C, S[v] += C;
        }

        M.assign(N, vector<ld>(N, 0));
        rep(i, N) rep(j, N) if (G[i][j]) M[i][j] = (ld)G[i][j] / (ld)S[i];
        rep(i, N) M[t][i] = 0; M[t][t] = 1;
        M_ = M;

        ld ans = M[s][t];
        rep(steps, 50000)
        {
            M__.assign(N, vector<ld>(N, 0));
            rep(i, N) rep(j, N)
            {
                ld n = 0;
                rep(k, N) M__[i][j] += M_[i][k] * M[k][j];
            }
            swap(M_, M__);

            ans += (ld)(steps + 2) * (M_[s][t] - M__[s][t]);
        }

        cout << ans << '\n';
    }
}