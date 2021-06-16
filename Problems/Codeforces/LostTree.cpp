#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

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

int N;
vector<int> R, F;
vector<vector<int>> G;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    F.resize(N), R.resize(N);

    cout << "? " << 1 << endl;
    rep(i, N) cin >> F[i];

    int p[2] = {0, 0};
    rep(i, N) p[F[i] & 1]++;

    int flag = (p[0] <= p[1]) ? 0 : 1;

    G.assign(N, {});
    if (flag == 0) rep(i, N) if (F[i] == 1) G[0].pb(i);
    rep(i, N) if (i && (F[i] & 1) == flag)
    {
        cout << "? " << i + 1 << endl;
        rep(j, N) cin >> R[j];
        rep(j, N) if (R[j] == 1) G[i].pb(j);
    }

    cout << "!" << endl;
    rep(i, N)
    {
        for (int j : G[i]) cout << i + 1 << ' ' << j + 1 << endl;
    }
}
