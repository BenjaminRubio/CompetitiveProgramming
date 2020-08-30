#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll N;
vector<ll> A;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll l = 1, r = (ll)pow(1e15, 1 / (float)(N - 1)) + 1ll;

    cerr << l << ' ' << r << '\n';
    
    ll ans = LLONG_MAX;
    repx(i, l, r + 1)
    {
        ll c = 0, p = 1;
        rep(j, N)
        {
            if (A[j] > p) c += A[j] - p;
            else c += p - A[j];
            p *= i;
            if (c > ans) break;
        }
        ans = min(ans, c);
    }

    cout << ans << '\n';
}