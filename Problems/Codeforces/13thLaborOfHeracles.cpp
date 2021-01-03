#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, u, v;
vector<int> W, D;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        W.resize(N); ll ans = 0;
        rep(i, N) { cin >> W[i]; ans += W[i]; }

        D.assign(N, 0);
        rep(_, N - 1)
        {
            cin >> u >> v; u--, v--;
            D[u]++, D[v]++;
        }

        priority_queue<int> q;
        rep(i, N) rep(_, D[i] - 1) q.push(W[i]);

        cout << ans << ' ';
        rep(i, N - 2)
        {
            ans += q.top(); q.pop();
            cout << ans << ' ';
        }
        cout << '\n';
    }
}