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

int T, N, M, c, d;
vector<vi> C, D, P;
vi SC, SD;

int DP[11][1100];

int dp(int i, int b)
{
    if (i == N) return 0;
    if (DP[i][b] != -1) return DP[i][b];

    int ans = dp(i + 1, b);
    for (int bb : P[i]) if ((b & bb) == bb)
        ans = max(ans, dp(i + 1, b & ~bb) + 1);

    return DP[i][b] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> N >> M;

        C.resize(N);
        SC.resize(N);
        rep(i, N)
        {
            cin >> SC[i];
            C[i].resize(SC[i]);
            rep(j, SC[i]) cin >> C[i][j];
        }

        D.assign(100, {});
        SD.resize(M);
        rep(i, M)
        {
            cin >> SD[i];
            D[i].resize(SD[i]);
            rep(j, SD[i]) cin >> D[i][j];
        }

        P.assign(N, {});
        rep(b, (1 << M) + 1) if (b)
        {
            vector<int> n(100, 0);
            rep(j, M) if (b & (1 << j)) for (int k : D[j]) n[k - 1]++;
            rep(i, N)
            {
                bool flag = 1;
                for (int j : C[i]) if (!n[j - 1]) flag = 0;

                if (flag) P[i].push_back(b);
            }
        }

        memset(DP, -1, sizeof DP);
        cout << dp(0, (1 << M) - 1) << '\n';
    }
}
