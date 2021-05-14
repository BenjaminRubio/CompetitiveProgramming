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
vector<vi> T;
vi D;

int P[3][3][410][410];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    D.resize(N);
    rep(i, N) cin >> D[i];

    T.assign(3, vi(N));
    rep(i, N) cin >> T[0][i];
    rep(i, N) cin >> T[1][i];
    rep(i, N) cin >> T[2][i];

    memset(P, 0, sizeof P);

    rep(a, 3) rep(b, 3) if (b > a) rep(i, N) rep(j, N) if (i != j)
    {
        int i_ = i, j_ = j, i0 = 1, i1 = 1, ip = (i + N - 1) % N, jp = (j + N - 1) % N;
        int tacci = 0, taccj = 0; bool ans = 1;
        while ((i_ != ip || i0 == 1) && (j_ != jp || i1 == 1))
        {
            int ti = tacci + (i0 ? T[a][i_] : D[i_]);
            int tj = taccj + (i1 ? T[b][j_] : D[j_]);
            if (ti <= tj)
            {
                tacci = ti;
                if (i0) i0 = 0;
                else i_ = (i_ + 1) % N, i0 = 1;
            }
            else
            {
                taccj = tj;
                if (i1) i1 = 0;
                else j_ = (j_ + 1) % N, i1 = 1;
            }
            ti = tacci + (i0 ? T[a][i_] : D[i_]);
            tj = taccj + (i1 ? T[b][j_] : D[j_]);
            if (i_ == j_ && i0 && i1 && tacci != tj && taccj != ti) { ans = 0; break; }
        }
        P[a][b][i][j] = ans;
        P[b][a][i][j] = ans;
    }

    rep(i, N) rep(j, N) rep(k, N) if (i != j && j != k && i != k)
    {
        if (P[0][1][i][j] && P[0][2][i][k] && P[1][2][j][k])
        {
            cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
            return 0;
        }
    }
    cout << "impossible\n";
}
