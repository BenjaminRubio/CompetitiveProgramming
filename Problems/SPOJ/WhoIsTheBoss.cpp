#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, Q, id, s, h;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;

        vector<pair<int, pair<int, int>>> data;
        rep(i, N)
        {
            cin >> id >> s >> h;
            data.emplace_back(s, make_pair(h, id));
        }

        sort(data.begin(), data.end());

        map<int, int> boss, count;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto e : data)
        {
            h = e.ss.ff, id = e.ss.ss;

            while (!q.empty() && q.top().ff <= h)
            {
                boss[q.top().ss] = id;
                count[id] += count[q.top().ss] + 1;
                q.pop();
            }

            q.emplace(h, id);
        }

        rep(_, Q)
        {
            cin >> id;
            cout << boss[id] << ' ' << count[id] << '\n';
        }
    }
}