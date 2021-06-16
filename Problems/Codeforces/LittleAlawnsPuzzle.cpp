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

const ll MOD = 1e9 + 7;

int T, N;
int M[2][400010], V[2][400010], P[2][400010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        rep(i, N) { cin >> M[0][i]; M[0][i]--; }
        rep(i, N) { cin >> M[1][i]; M[1][i]--; }

        rep(i, N) V[0][i] = 0, V[1][i] = 0;

        rep(i, N) P[0][M[0][i]] = i, P[1][M[1][i]] = i;

        int ans = 0;
        rep(i, N)
        {
            if (!V[0][i])
            {
                int j = i;
                while (V[0][j] == 0)
                {
                    V[0][j] = 1, V[1][j] = 1;
                    j = P[0][M[1][j]];
                }

                ans++;
            }
        }

        ll final = 1;
        rep(_, ans) final = (final * 2ll) % MOD;

        cout << final << '\n';
    }   
}
