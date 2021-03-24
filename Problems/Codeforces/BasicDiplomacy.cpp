#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M, k, u;
vector<vector<int>> P;
vector<int> C, ans;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        P.assign(M, {});
        C.assign(N, 0);
        ans.assign(M, -1);

        bool flagg = 1;
        rep(i, M)
        {
            cin >> k;
            if (k > 1) rep(_, k) { cin >> u; P[i].push_back(u - 1); }
            else { cin >> u; C[u - 1]++; ans[i] = u; }
        }

        rep(i, N) if (C[i] > (M / 2 + (M & 1))) flagg = 0;

        if (flagg) rep(i, M) if (ans[i] == -1)
        {
            bool flag = 0;
            for (int u : P[i]) if (C[u] < (M / 2 + (M & 1)))
            {
                ans[i] = u + 1;
                C[u]++;
                flag = 1;
                break;
            }
            if (!flag) { flagg = 0; break; }
        }

        if (!flagg) { cout << "NO\n"; continue; }

        cout << "YES\n";
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}