#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N; ll W, w;
vector<pair<ll, int>> E;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> W; E.clear();

        rep(i, N) { cin >> w; E.emplace_back(w, i); }

        sort(E.rbegin(), E.rend());

        ll C = 0; int i = 0;
        vector<int> ans;
        while (i < N && C < W - W / 2ll)
        {
            if (C + E[i].first <= W)
            {
                C += E[i].first;
                ans.push_back(E[i].second);
            }
            i++;
        }

        sort(ans.begin(), ans.end());

        if (C < W - W / 2ll) cout << -1 << '\n';
        else
        {
            cout << ans.size() << '\n';
            for (int i : ans) cout << i + 1 << ' ';
            cout << '\n';
        }
    }
}