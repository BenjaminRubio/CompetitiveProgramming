#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M; string s;
map<string, vector<int>> S1, S2;

int main()
{
    cin >> T;
    while (T--)
    {
        S1.clear(), S2.clear();

        cin >> N;

        rep(i, N)
        {
            cin >> s;
            
            cin >> M;
            rep(j, M) { cin >> s; S1[s].push_back(i); }
            cin >> M;
            rep(j, M) { cin >> s; S2[s].push_back(i); }
        }

        vector<pair<string, string>> ans;
        for (auto &e1 : S1) for (auto &e2 : S2) if (e1.second == e2.second)
            ans.emplace_back(e1.first, e2.first);

        sort(ans.begin(), ans.end());

        for (auto &e : ans) cout << '(' << e.first << ", " << e.second << ')' << '\n';
        cout << '\n';
    }
}