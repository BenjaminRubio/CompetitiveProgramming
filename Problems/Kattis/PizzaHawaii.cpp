#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M; string s;
map<string, int> S1, S2;
map<int, vector<string>> M1, M2;

int main()
{
    cin >> T;
    while (T--)
    {
        S1.clear(), S2.clear(), M1.clear(), M2.clear();

        cin >> N;

        rep(i, N)
        {
            cin >> s;
            
            cin >> M;
            rep(j, M) { cin >> s; S1[s] |= (1 << i); }
            cin >> M;
            rep(j, M) { cin >> s; S2[s] |= (1 << i); }
        }

        for (auto &e : S1) M1[e.second].push_back(e.first);
        for (auto &e : S2) M2[e.second].push_back(e.first);

        vector<pair<string, string>> ans;
        for (auto &e : M1) for (string s1 : e.second) for (string s2 : M2[e.first])
            ans.emplace_back(s1, s2);

        sort(ans.begin(), ans.end());

        for (auto &e : ans) cout << '(' << e.first << ", " << e.second << ')' << '\n';
        cout << '\n';
    }
}