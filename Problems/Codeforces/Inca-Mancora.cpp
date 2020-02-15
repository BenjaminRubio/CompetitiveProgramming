#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, Q, k, a, b;
vector<bool> f;
set<pair<int, int>> queries;

int main()
{
    cin >> N >> M >> Q;

    f.assign(N * (N - 1) / 2 + 1, 0);
    rep(i, M)
    {
        cin >> k >> a >> b; a--; b--;
        int lev = N - (b - a) + 1;
        int id = N * (N - 1) / 2 - lev * (lev - 1) / 2 + a;

        f[id] = !f[id];
        f[id + k] = !f[id + k];
    }

    rep(i, Q)
    {
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        int lev = N - (b - a) + 1;
        int id = N * (N - 1) / 2 - lev * (lev - 1) / 2 + a;

        queries.emplace(id, i);
    }

    bool s = 0;
    vector<bool> ans(Q);
    auto it = queries.begin();
    int i = 0, last = -1;
    while (i < N * (N - 1) / 2)
    {
        if (i > last and f[i]) s = !s;
        if (i == it->ff) { ans[it++->ss] = s; last = i; continue; }
        if (it == queries.end()) break;
        i++;
    }

    rep(i, Q)
    {
        if (ans[i]) cout << "SI\n";
        else cout << "NO\n";
    }
}