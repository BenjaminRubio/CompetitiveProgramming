#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define eb emplace_back

int N, M, A, B, u, v;
vector<vector<int>> g;
vector<int> d;

struct Metal
{
    int deg, id;
    Metal(int deg, int id) : deg(deg), id(id) {}
    bool operator<(const Metal &m) const
    {
        return deg < m.deg or (deg == m.deg and id < m.id);
    }
};

int main()
{
    cin >> N >> M >> A >> B;

    g.resize(N);
    d.assign(N, 0);
    rep(i, M)
    {
        cin >> u >> v;
        g[u - 1].eb(v - 1); g[v - 1].eb(u - 1);
        d[u - 1]++; d[v - 1]++;
    }

    set<Metal> s;
    rep(i, N) s.emplace(d[i], i);

    while (!s.empty())
    {
        int n = s.size();

        int id;
        if (s.begin()->deg < A) id = s.begin()->id;
        else if (n - s.rbegin()->deg - 1 < B) id = s.rbegin()->id;
        else break;

        for (int e : g[id])
        {
            if (s.find(Metal(d[e], e)) != s.end())
            {
                s.erase(Metal(d[e], e)); d[e]--;
                if (d[e]) s.insert(Metal(d[e], e));
            }
        }
        s.erase(Metal(d[id], id));
    }

    cout << s.size() << '\n';
}