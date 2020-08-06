#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> par;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

ll S, T, F, N, X;
priority_queue<par, vector<par>, greater<par>> E;
queue<ll> Q;

int main()
{
    cin >> S >> F >> T >> N;
    rep(i, N) { cin >> X; E.emplace(X, 0); }
    E.emplace(S, 1);

    ll ans = -1, aux = LLONG_MAX; bool flag = 1;
    while (!E.empty())
    {
        par e = E.top(); E.pop();
        if (e.ss == 0)
        {
            if (!flag)
            {
                if (e.ff + T > F) break;
                E.emplace(e.ff + T, 1);
                flag = 1;
            }
            else Q.push(e.ff);
        }
        else
        {
            if (!Q.empty())
            {
                ll t = Q.front(); Q.pop();
                if (e.ff + T > F) break;
                if (aux > e.ff - t + 1) ans = t - 1, aux = e.ff - t + 1;
                E.emplace(e.ff + T, 1);
            }
            else { flag = 0; if (e.ff + T <= F) ans = e.ff, aux = 0; }
        }
    }

    cout << ans << '\n';
}