#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll T, N;
vector<ll> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        repx(i, 2, N) if (A[0] + A[1] <= A[i])
        { cout << 1 << ' ' << 2 << ' ' << i + 1 << '\n'; goto next; }

        cout << -1 << '\n';

        next:
        continue;
    }
}