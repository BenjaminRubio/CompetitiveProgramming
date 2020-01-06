#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, T, B;
vector<vector<int>> g;

int solve(int i)
{
    if (g[i].empty())
        return 1;

    vector<int> s;
    for (int j : g[i])
        s.push_back(solve(j));

    sort(s.begin(), s.end());

    double t = (double)T / 100.0 * (double)g[i].size();
    int ans = 0;
    int ind = 0;
    while (ind < t)
        ans += s[ind++];

    return ans;
}

int main()
{
    while (cin >> N >> T)
    {
        if (N == 0 && T == 0)
            break;

        g.assign(N + 1, {});
        rep(i, N)
        {
            cin >> B;
            g[B].push_back(i + 1);
        }

        cout << solve(0) << '\n';
    }
}