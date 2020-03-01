#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int n;
priority_queue<pair<int, int>> q1;
stack<pair<int, int>> q2;
vector<int> s, rem;
vector<pair<int, int>> l, r;
char c;

int main()
{
    cin >> n;
    l.resize(n); r.resize(n); rem.assign(n, 0);

    rep(i, n)
    {
        cin >> c;
        s.push_back(c);
        if (i > 0) r[i - 1] = make_pair(c, i);
        if (i < n - 1) l[i + 1] = make_pair(c, i);
        q1.emplace(c, i);
    }
    l[0] = make_pair(-1, -1);
    r[n - 1] = make_pair(-1, -1);

    int ans = 0;
    rep(_, n)
    {
        while (!q1.empty())
        {
            int v = q1.top().ff, id = q1.top().ss; q2.push(q1.top()); q1.pop();

            if (!rem[id] and (l[id].ff == s[id] - 1 or r[id].ff == s[id] - 1))
            {
                rem[id] = 1;
                if (l[id].ss != -1) r[l[id].ss] = r[id];
                if (r[id].ss != -1) l[r[id].ss] = l[id]; 
                ans++;
                break;
            }
        }

        while (!q2.empty()) { q1.push(q2.top()); q2.pop(); }
    }

    cout << ans << '\n';
}