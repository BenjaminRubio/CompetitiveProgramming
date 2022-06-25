#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N, M; char c;
vvi G, V;
vi S;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int t)
{
    V[x][y] = t; int ans = 1;
    rep(k, 4)
    {
        int x_ = x + dx[k], y_ = y + dy[k];
        if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M && !V[x_][y_]) ans += dfs(x_, y_, t);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    G.assign(N, vi(M));
    rep(i, N) rep(j, M)
    {
        cin >> c;
        G[i][j] = (c == '*');
    }

    V = G; int t = 2;
    rep(i, N) rep(j, M) if (!V[i][j])
    {
        int s = dfs(i, j, t);
        t++; S.pb(s);
    }

    rep(i, N)
    {
        rep(j, M)
        {
            if (G[i][j] == 0) cout << '.';
            else
            {
                set<int> adj;
                rep(k, 4)
                {
                    int x_ = i + dx[k], y_ = j + dy[k];
                    if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M && V[x_][y_] > 1) adj.insert(V[x_][y_]);
                }

                int ans = 1;
                for (int x : adj) ans += S[x - 2];
                cout << (ans % 10);
            }
        }
        cout << '\n';
    }
}
