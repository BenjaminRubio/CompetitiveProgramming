#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<ll, int> par;

int N, M;
vector<ll> C, W;

int main()
{
    cin >> N >> M;

    C.resize(N); W.resize(N);
    rep(i, N) cin >> C[i];
    rep(i, N) cin >> W[i];

    vector<pair<int, int>> ans(N);

    rep(i, N)
    {
        ans[i].first = C[i] / 100;
        C[i] %= 100;
    }

    priority_queue<par, vector<par>, greater<par>> q;

    ll tot = 0;
    rep(i, N)
    {
        if (M >= C[i])
        {
            M -= C[i];
            if (C[i]) q.emplace(W[i] * (100 - C[i]), i);
            ans[i].second = C[i];
            continue;
        }

        M += 100 - C[i];
        par top = !q.empty() ? q.top() : make_pair((ll)1e9, 0);
        if (W[i] * (100 - C[i]) < top.first)
        {
            tot += W[i] * (100 - C[i]);
            ans[i].first++;
        }
        else
        {
            ans[top.second].first++; ans[top.second].second = 0;
            tot += top.first; q.pop();
            q.emplace(W[i] * (100 - C[i]), i);
            ans[i].second = C[i];
        }
    }

    cout << tot << '\n';
    rep(i, N) cout << ans[i].first << ' ' << ans[i].second << '\n';
}