#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N;
vector<int> A;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    vector<pair<int, int>> ans;
    stack<pair<int, int>> s1, s2; int f = N - 1;
    for (int i = N - 1; i >= 0; i--)
    {
        int n = A[i];

        if (n == 1) ans.emplace_back(i, f), s1.emplace(i, f--);
        if (n == 2)
        {
            if (s1.empty()) { cout << -1 << '\n'; return 0; }
            auto c = s1.top(); s1.pop();
            ans.emplace_back(i, c.ss);
            s2.emplace(i, c.ss);
        }
        if (n == 3)
        {
            if (s2.empty() && s1.empty()) { cout << -1 << '\n'; return 0; }
            pair<int, int> c;
            if (s2.empty()) { c = s1.top(); s1.pop(); }
            else { c = s2.top(); s2.pop(); }
            ans.emplace_back(i, f), ans.emplace_back(c.ff, f);
            s2.emplace(i, f--);
        }
    }

    cout << ans.size() << '\n';
    for (auto &e : ans) cout << e.ss + 1 << ' ' << e.ff + 1 << '\n';
}