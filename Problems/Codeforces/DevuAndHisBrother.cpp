#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M;
vector<ll> A, B;

ll calc(ll m)
{
    ll ans = 0;
    rep(i, N) ans += max(0ll, m - A[i]);
    rep(i, M) ans += max(0ll, B[i] - m);
    return ans;
}

int main()
{
    cin >> N >> M;

    A.resize(N); rep(i, N) cin >> A[i];
    B.resize(M); rep(i, M) cin >> B[i];

    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll m = (l + r) / 2;

        if (calc(m) <= calc(m + 1)) r = m;
        else l = m + 1;
    }
    
    cout << calc(l) << '\n';
}