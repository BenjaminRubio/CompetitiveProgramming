#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, K;
vector<ll> A;

ll cost(int i, ll c)
{
    ll ans = (A[i] / c + 1ll) * (A[i] / c + 1ll) * (A[i] % c);
    ans += (A[i] / c) * (A[i] / c) * (c - A[i] % c);
    return ans;
}

int main()
{
    cin >> N >> K;

    A.resize(N);
    rep(i, N) cin >> A[i];

    priority_queue<pair<ll, pair<int, int>>> Q;
    rep(i, N) Q.emplace(cost(i, 1) - cost(i, 2), make_pair(i, 1));

    int c = N;
    while (c++ < K)
    {
        auto e = Q.top(); Q.pop(); e.ss.ss++;
        Q.emplace(cost(e.ss.ff, e.ss.ss) - cost(e.ss.ff, e.ss.ss + 1), e.ss);
    }

    ll ans = 0;
    while (!Q.empty())
    {
        auto e = Q.top(); Q.pop();
        ans += cost(e.ss.ff, e.ss.ss);
    }

    cout << ans << '\n';
}