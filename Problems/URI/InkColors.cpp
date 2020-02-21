#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, u;
vector<vector<int>> g;
stack<int> order;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        order.push(u);
        for (int v : g[u]) q.push(v);
    }
}

int main()
{
    cin >> N;

    g.assign(N, {});
    rep(i, N - 1)
    {
        cin >> u; u--;
        g[u].push_back(i + 1);
    }

    bfs(0);

    int ans = 0;
    vector<bool> disp(N, true);
    vector<int> cnt(N, 0);
    while (!order.empty())
    {
        int u = order.top(); order.pop();
        for (int v : g[u]) if (disp[v]) cnt[u]++;

        if (cnt[u] < 3) continue;

        bool pos = false;
        for (int v : g[u]) if (disp[v] and cnt[v] > 1) pos = true;

        if (u != 0 and pos) ans++, cnt[u] -= 3, disp[u] = false;
    }

    cout << ans << '\n';
}