#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

const int INF = 1e9;

int R, C, W, sr, sc, tr, tc, c1, c2, r1, r2;
vector<vector<bool>> M;
vector<vector<int>> cost;
int dr[24] = {0, 0, 1, -1, 1, -1, 1, -1, 0, 0, 2, -2, 
              -2, -2, -1, -1, 1, 1, 2, 2, 2, -2, 2, -2};
int dc[24] = {1, -1, 0, 0, 1, -1, -1, 1, 2, -2, 0, 0,
              -1, 1, 2, -2, 2, -2, 1, -1, 2, -2, -2, 2};

int cst(int k)
{
    if (k < 4) return 2;
    if (k < 8) return 3;
    if (k < 12) return 5;
    if (k < 20) return 6;
    return 7;
}

struct Edge
{
    int r, c, w;
    Edge(int r, int c, int w) : r(r), c(c), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int dijkstra(int sr, int sc, int tr, int tc)
{
    cost.assign(R, vector<int>(C, INF));
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;

    q.emplace(sr, sc, 0);
    cost[sr][sc] = 0;
    while (!q.empty())
    {
        int r = q.top().r, c = q.top().c, w = q.top().w; q.pop();

        if (cost[r][c] < w) continue;

        rep(k, 24)
        {
            int r_ = r + dr[k], c_ = c + dc[k];
            if (r_ >= 0 && r_ < R && c_ >= 0 && c_ < C && M[r_][c_])
            {
                if (cost[r_][c_] > cst(k) + w)
                {
                    cost[r_][c_] = cst(k) + w;
                    q.emplace(r_, c_, cost[r_][c_]);
                }
            }
        }
    }
    return cost[tr][tc];
}

int main()
{
    while (cin >> R >> C)
    {
        if (R == 0) break;

        cin >> sr >> sc >> tr >> tc; sr--; sc--; tr--; tc--;
        
        cin >> W;

        M.assign(R, vector<bool>(C, true));
        rep(_, W)
        {
            cin >> r1 >> c1 >> r2 >> c2; c1--; r1--;
            repx(r, r1, r2) repx(c, c1, c2) M[r][c] = false;
        }

        int ans = dijkstra(sr, sc, tr, tc);

        if (ans < INF) cout << ans << '\n';
        else cout << "impossible\n";
    }
}