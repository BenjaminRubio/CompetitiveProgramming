#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, x; char ch;
vector<pair<int, int>> E;

int main()
{
    cin >> N;

    rep(_, 2 * N)
    {
        cin >> ch;
        if (ch == '+') E.emplace_back(0, 0);
        else { cin >> x; E.emplace_back(1, x); }
    }

    reverse(E.begin(), E.end());

    priority_queue<int, vector<int>, greater<int>> Q;
    vector<int> ans;
    for (auto &e : E)
    {
        if (e.ff == 0)
        {
            if (Q.empty()) { cout << "NO\n"; return 0; }
            ans.push_back(Q.top()); Q.pop();
        }
        else
        {
            if (!Q.empty() && Q.top() < e.ss) { cout << "NO\n"; return 0; }
            Q.push(e.ss);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}