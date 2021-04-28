#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N, M, K; char c;
vector<vi> D, m;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string dirs = "DLRU";

int main()
{
    cin >> N >> M >> K;

    if (K & 1) { cout << "IMPOSSIBLE\n"; return 0; }

    int pi, pj, x, y;
    m.assign(N, vi(M, 0));
    rep(i, N) rep(j, M)
    {
        cin >> c;
        m[i][j] = (c == '*');
        if (c == 'X') pi = i, pj = j;
    }

    bool flag = 0;
    queue<pair<pii, int>> Q; Q.emplace(mp(pi, pj), 0);
    D.assign(N, vi(M, -1)); D[pi][pj] = 0;
    while (!Q.empty())
    {
        tie(x, y) = Q.front().ff;
        D[x][y] = Q.front().ss; Q.pop();

        rep(k, 4)
        {
            int x_ = x + dx[k], y_ = y + dy[k];
            if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M && !m[x_][y_] && D[x_][y_] == -1)
            {
                flag = 1;
                D[x_][y_] = 0;
                Q.emplace(mp(x_, y_), D[x][y] + 1);
            }
        }
    }

    if (!flag) { cout << "IMPOSSIBLE\n"; return 0; }

    x = pi, y = pj;
    while (K--) rep(k, 4)
    {
        int x_ = x + dx[k], y_ = y + dy[k];
        if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M && !m[x_][y_] && D[x_][y_] <= K)
        {
            cout << dirs[k];
            x = x_, y = y_;
            break;
        }
    }
    cout << '\n';
}