#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll n, k, s, m;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    rep(i, k) q.push(0);

    rep(i, n)
    {
        cin >> s >> m;

        ll nxt = q.top(); q.pop();
        cout << max(s, nxt) + m << '\n';
        q.push(max(s, nxt) + m);
    }
}