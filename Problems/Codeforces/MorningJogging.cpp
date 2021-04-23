#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
vector<vector<int>> B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
        B.assign(N, vector<int>(M));
        rep(i, N) rep(j, M) { cin >> B[i][j]; Q.push({B[i][j], {i, j}}); }

        vector<pair<int, int>> S; int c = 0;
        while (c++ < M) { S.push_back(Q.top().second); Q.pop(); }

        sort(S.begin(), S.end());

        // rep(i, M) cerr << S[i].first << ' ' << S[i].second << '\n';

        int id = 0, k = 0;
        rep(i, N)
        {
            set<int> Sp;
            while (k < M && S[k].first == i) Sp.insert(S[k].second), k++;

            vector<int> ans(M); set<int> ids;
            for (int x : Sp) { ans[id] = B[i][x]; ids.insert(id++); }

            int p = 0;
            rep(j, M)
            {
                while (ids.count(p)) p++;
                if (!Sp.count(j)) ans[p++] = B[i][j];
            }

            rep(j, M) cout << ans[j] << ' ';
            cout << '\n';
        }
    }
}