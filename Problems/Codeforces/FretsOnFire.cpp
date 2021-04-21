#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll N, Q, l, r;
vector<ll> S;

int main()
{
    cin >> N;

    S.resize(N); rep(i, N) cin >> S[i];

    sort(S.begin(), S.end());

    vector<ll> D;
    rep(i, N - 1) D.push_back(S[i + 1] - S[i]);

    sort(D.begin(), D.end());

    cin >> Q;
    vector<pair<ll, ll>> E;
    rep(i, Q)
    {
        cin >> l >> r; r = r - l + 1;
        E.emplace_back(r, i);
    }

    sort(E.begin(), E.end());

    vector<ll> ans(Q);
    ll active = N, offset = 0, i = 0;
    for (auto &e : E)
    {
        while (i < N - 1 && D[i] < e.ff) offset += D[i++], active--;
        ans[e.ss] = active * e.ff + offset;
    }

    rep(i, Q) cout << ans[i] << ' ';
    cout << '\n';
}