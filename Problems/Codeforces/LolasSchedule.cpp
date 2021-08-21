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

int N, X, S, D;
int P[300001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> X;

    vp E;
    rep(_, N)
    {
        cin >> S >> D; D += S + 1;
        E.eb(S, 0), E.eb(D, 1);
    }

    sort(E.begin(), E.end());

    int i = 0, c = 0;
    rep(p, 300001)
    {
        while (i < 2 * N && E[i].ff == p)
        {
            if (E[i].ss == 0) c++;
            if (E[i].ss == 1) c--;
            i++;
        }

        P[p] = (c > 0);
    }

    for (int p = 300000; p >= 0; p--)
    {
        if (p + X <= 300000) P[p] += P[p + X];
    }

    int id, ans = INT_MAX;
    rep(p, 8 * 60 + 1)
    {
        if (P[p] < ans) ans = P[p], id = p;
    }

    cout << id << ' ' << ans << '\n';
}
