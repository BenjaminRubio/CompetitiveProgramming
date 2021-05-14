#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

ll N;
vector<ll> X, V, L, R, A;

db timed(db d, db v)
{
    return d / v;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    L.assign(N, -1); R.assign(N, -1);
    rep(i, N - 1) L[i + 1] = i, R[i] = i + 1;

    X.resize(N), V.resize(N);
    rep(i, N) cin >> X[i] >> V[i];

    priority_queue<pair<db, pair<ll, ll>>, vector<pair<db, pair<ll, ll>>>, greater<pair<db, pair<ll, ll>>>> S;
    rep(i, N)
    {
        if (i > 0 && V[i - 1] > V[i])
        {
            S.emplace(timed(X[i] - X[i - 1], V[i - 1] - V[i]), mp(i - 1, i));
        }
        if (i < N - 1 && V[i] > V[i + 1])
        {
            S.emplace(timed(X[i + 1] - X[i], V[i] - V[i + 1]), mp(i, i + 1));
        }
    }

    int ans = N;
    A.assign(N, 0); int i, j, i_, j_;
    while (!S.empty())
    {
        tie(i, j) = S.top().second; S.pop();
        if (A[i] || A[j]) continue;
        
        ans -= 2;
        A[i] = 1, A[j] = 1;

        i_ = L[i], j_ = R[j];
        if (i_ != -1 && j_ != -1 && V[i_] > V[j_])
            S.emplace(timed(X[j_] - X[i_], V[i_] - V[j_]), mp(i_, j_));

        if (i_ != -1) R[i_] = j_;
        if (j_ != -1) L[j_] = i_;
    }

    cout << ans << '\n';
    rep(i, N) if (!A[i]) cout << i + 1 << ' ';
    cout << '\n';
}
