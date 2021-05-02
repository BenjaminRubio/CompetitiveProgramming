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

int T, N, M, X, h;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> M >> X;

        vp H(N);
        rep(i, N) { cin >> h; H.eb(h, i); }

        sort(H.rbegin(), H.rend());
        priority_queue<pii, vp, greater<pii>> S;
        rep(i, M) S.emplace(0, i);

        vi ans(N); int s, p;
        rep(i, N)
        {
            tie(s, p) = S.top(); S.pop();
            ans[H[i].ss] = p; s += H[i].ff;
            S.emplace(s, p);
        }

        cout << "YES\n";
        rep(i, N) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }    
}
