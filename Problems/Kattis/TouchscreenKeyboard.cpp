#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
string s, w;
vector<vector<int>> K = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                         {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                         {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};

int main()
{
    map<char, int> X, Y;
    rep(i, 3) rep(j, K[i].size()) X[K[i][j]] = i, Y[K[i][j]] = j;

    cin >> T;
    while (T--)
    {
        cin >> s >> N;

        vector<pair<int, string>> ans;

        rep(_, N)
        {
            cin >> w;

            int score = 0;
            rep(i, w.size()) score += abs(X[w[i]] - X[s[i]]) + abs(Y[w[i]] - Y[s[i]]);

            ans.emplace_back(score, w);
        }

        sort(ans.begin(), ans.end());

        for (auto e : ans) cout << e.second << ' ' << e.first << '\n';
    }
}