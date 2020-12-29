#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct AC
{
    static const int MAX = 2000, ASZ = 200;
    int N[MAX][ASZ] = {0}, L[MAX] = {0}, E[MAX] = {0}, c = 0;
    void add(string s)
    {
        int p = 0;
        for (char t : s)
        {
            if (!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
        } E[p] = 1;
    }
    void init()
    {
        queue<int> q; q.push(0); L[0] = -1;
        while (!q.empty())
        {
            int p = q.front(); q.pop();
            rep(c, ASZ)
            {
                int u = N[p][c]; if (!u) continue;
                L[u] = L[p] == -1 ? 0 : N[L[p]][c], q.push(u);
            }
            if (p) rep(c, ASZ) if (!N[p][c]) N[p][c] = N[L[p]][c];
        }
    }
};

int N, M;
string e, s;

int main()
{
    while (cin >> N >> M && N)
    {
        AC ac;
        rep(_, N) { cin >> e; ac.add(e); }

        ac.init();
        getline(cin, s);

        int ans = 0;
        rep(_, M)
        {
            getline(cin, s); int p = 0;
            for (char c : s)
            {
                while (p && !ac.N[p][c]) p = ac.L[p];
                p = ac.N[p][c]; int pp = p;
                while (pp)
                {
                    if (ac.E[pp]) { ans++, p = 0; break; }
                    pp = ac.L[pp];
                }
            }
        }

        cout << ans << '\n';
    }
}