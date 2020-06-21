#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    int p, v, c;
    Node(int p, int v, int c) : p(p), v(v), c(c) {}
    bool operator>(const Node &n) const { return c > n.c; }
};

int N, M, l, s, c;
vector<int> E, E_;
vector<vector<int>> S, C;

int main()
{
    while (cin >> N >> M)
    {
        E.resize(N);
        rep(i, N) cin >> E[i];

        E_.assign(N + 1, 0);
        rep(i, N + 1) E_[i] = (i ? E[i - 1] + E_[i - 1] : 0);

        S.assign(N, {}); C.assign(N, {});
        rep(_, M)
        {
            cin >> l >> s >> c; l--;
            S[l].push_back(s); C[l].push_back(c);
        }

        priority_queue<Node, vector<Node>, greater<Node>> q;
        rep(i, S[0].size()) q.emplace(0, S[0][i], C[0][i]);
        int ans = -1; l = 1;
        while (!q.empty())
        {
            Node u = q.top(); q.pop();

            if (u.v >= E_[N] - E_[u.p]) { ans = u.c; break; }

            while (u.v >= E_[l] - E_[u.p])
            { rep(i, S[l].size()) q.emplace(l, S[l][i], u.c + C[l][i]); l++; }
        }
        
        cout << ans << '\n';
    }
}