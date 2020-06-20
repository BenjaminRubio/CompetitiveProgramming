#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, K, u, v, w;
vector<vector<int>> D;

int main()
{
    cin >> N;

    D.assign(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> D[i][j];

    ll sum = 0;
    rep(i, N) repx(j, i + 1, N) sum += D[i][j];

    cin >> K;
    while (K--)
    {
        cin >> u >> v >> w; u--, v--;

        rep(i, N) repx(j, i + 1, N)
        {
            int aux = min(D[i][u] + w + D[v][j], D[i][v] + w + D[u][j]);
            if (D[i][j] > aux) sum += aux - D[i][j], D[i][j] = D[j][i] = aux;
        }

        cout << sum << ' ';
    }
    cout << '\n';
}