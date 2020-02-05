#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K;
vector<vector<int>> scores;

int score(int T)
{
    int ans = 0;
    rep(i, N)
    {
        int l = 0;
        for (int p : scores[i])
            if (p < T) l++;

        ans += abs((int)scores[i].size() - 2 * l);
    }

    return ans;
}

int main()
{
    while (cin >> N)
    {
        if (N == 0) break;

        scores.assign(N, {});
        rep(i, N)
        {
            cin >> K;

            scores[i].resize(K);
            rep(j, K) cin >> scores[i][j];
        }

        int m = 1e9;
        rep(i, 1001) m = min(m, score(i + 1));

        cout << m << '\n';
    }
}