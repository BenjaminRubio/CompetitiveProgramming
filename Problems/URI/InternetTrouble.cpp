#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ff first
#define ss second

ll N, B, C;
ll P[6001], S[6001], H[6000], M[6000][6000];

ll cost(ll i, ll j)
{
    ll m = P[j + 1] - P[i], s = S[j + 1] - S[i];
    ll m1 = max(round((double)m / (double)s) - 1., 0.);
    ll m2 = round((double)m / (double)s);
    ll c1 = (P[j + 1] - 2 * P[m1] + P[i]) - (S[j + 1] - 2 * S[m1] + S[i]) * m1;
    ll c2 = (P[j + 1] - 2 * P[m2] + P[i]) - (S[j + 1] - 2 * S[m2] + S[i]) * m2;
    return min(c1, c2);
}

ll data[6000][2];

void compute(ll l, ll r, ll optl, ll optr, ll i)
{
    if (l > r) return;

    ll mid = (l + r) / 2;
    pair<ll, ll> best = {M[0][mid], -1};

    repx(k, max(1ll, optl), min(mid, optr) + 1)
        best = min(best, {data[k - 1][i] + M[k][mid], k});

    data[mid][i ^ 1] = best.ff;

    compute(l, mid - 1, optl, best.ss, i);
    compute(mid + 1, r, best.ss, optr, i);
}

int main()
{
    cin >> N >> B >> C;
    cerr << N << '\n';
    rep(i, N)
    {
        cin >> H[i];
        P[i + 1] = P[i] + H[i] * i;
        S[i + 1] = S[i] + H[i];
    }

    rep(i, N) repx(j, i + 1, N) M[i][j] = cost(i, j);

    rep(i, N) data[i][0] = M[0][i];
    cout << data[N - 1][0] * C + B;
    rep(_, N - 1)
    {
        compute(0, N - 1, 0, N - 1, _ & 1);
        cout << ' ' << data[N - 1][_ & 1 ^ 1] * C + (_ + 2) * B;
    }

    cout << '\n';
}