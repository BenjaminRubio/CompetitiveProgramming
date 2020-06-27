#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int R, M, d;

int P[10000], N[10000];
string ans;

int main()
{
    int C = 0;
    while (cin >> R >> M)
    {
        ans.clear();
        set<int> valid = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        rep(_, M) { cin >> d; valid.erase(d); }

        memset(N, -1, sizeof N); memset(P, -1, sizeof P);

        queue<int> q; q.push(0); N[0] = -1; int flag = -1;
        while (!q.empty())
        {
            int r = q.front(); q.pop(); flag++;
            for (int i : valid) if (i || flag)
            {
                int nr = (r * 10 + i) % R;
                if (!nr)
                {
                    ans += '0' + i;
                    while (P[r] != -1) ans += '0' + N[r], r = P[r];
                    reverse(ans.begin(), ans.end());
                    goto res;
                }
                if (N[nr] == -1) { q.push(nr); P[nr] = r, N[nr] = i; }
            }
        }

        res:
        cout << "Case " << ++C << ": ";
        if (!ans.empty()) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}