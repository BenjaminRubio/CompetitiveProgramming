#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int l, h, r;
vector<int> heigths;
set<pair<int, int>> events;
set<pair<int, int>> sweep;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    while (cin >> l >> h >> r)
    {
        events.insert({l, i});
        events.insert({r, i});
        heigths.push_back(h);
        i++;
    }
    events.insert({INT_MAX, i});
    heigths.push_back(0);

    int last = -1;
    int curr = -1;
    for (auto e : events)
    {
        // cerr << e.first << ' ' << e.second << '\n';
        int cand;
        if (sweep.size())
            cand = (--sweep.end())->first;
        else
            cand = 0;
        if (last != -1 && e.first != last && cand != curr)
        {
            cout << last << ' ';
            curr = cand;
            if (e.first == INT_MAX)
                cout << curr << '\n';
            else
                cout << curr << ' ';
        }
        if (sweep.count({heigths[e.second], e.second}))
            sweep.erase({heigths[e.second], e.second});
        else
            sweep.insert({heigths[e.second], e.second});
        last = e.first;
    }
}