#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second
typedef long long ll;

int T, n, m, t, x, y, w, k, l;
int W[6010][6010];
map<int, vector<pair<int, int>>> G;

bool in(int x, int y)
{
    return x >= 0 and x < 6000 and y >= 0 and y < 6000 and W[x][y] != -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i, 6001) rep(j, 6001) if (i * i + j * j < 1e7 + 1)
    {
        G[i * i + j * j].emplace_back(i, j);
        if (j) G[i * i + j * j].emplace_back(i, -j);
        if (i) G[i * i + j * j].emplace_back(-i, j);
        if (i and j) G[i * i + j * j].emplace_back(-i, -j);
    }

    cin >> T;
    rep(k, T)
    {
        cout << "Case #" << k + 1 << ":\n";
        memset(W, -1, sizeof W);
        cin >> n >> m; l = 0;

        rep(_, n) { cin >> x >> y >> w; W[x - 1][y - 1] = w; }
        rep(_, m)
        {
            cin >> t >> x >> y;
            x = (x + l) % 6000 + 1; y = (y + l) % 6000 + 1;
            
            if (t == 1) { cin >> w; W[x - 1][y - 1] = w; }
            if (t == 2) { W[x - 1][y - 1] = -1; }
            if (t == 3)
            {
                cin >> k >> w;
                for (auto p : G[k]) if (in(x + p.ff - 1, y + p.ss - 1))
                    W[x + p.ff - 1][y + p.ss - 1] += w;
            }
            if (t == 4)
            {
                cin >> k;
                ll ans = 0;
                for (auto p : G[k]) if (in(x + p.ff - 1, y + p.ss - 1))
                    ans += W[x + p.ff - 1][y + p.ss - 1];
                cout << ans << '\n'; l = ans % 6000;
            }
        }
    }
}