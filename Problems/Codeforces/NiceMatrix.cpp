#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll T, N, M;
vector<vector<ll>> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        A.assign(N, vector<ll>(M));
        rep(i, N) rep(j, M) cin >> A[i][j];

        ll ans = 0;
        rep(i, N - N / 2ll) rep(j, M - M / 2ll)
        {
            set<pair<ll, ll>> s = {{i, j}, {i, M - j - 1}, {N - i - 1, j}, {N - i - 1, M - j - 1}};
            ll ch = LLONG_MAX;
            for (auto &p : s)
            {
                ll sum = 0;
                for (auto &q : s)  sum += abs(A[p.ff][p.ss] - A[q.ff][q.ss]);
                ch = min(ch, sum);
            }
            ans += ch;
        }

        cout << ans << '\n';
    }
}