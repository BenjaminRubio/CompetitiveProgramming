#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

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

int A[3], W[2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> A[0] >> A[1] >> A[2] >> W[0] >> W[1];

    bool ans = 0;
    rep(a, 3) rep(b, 3) if (a != b)
    {
        int c = 3 - a - b;

        if (2 * A[c] + A[a] <= W[0] && 2 * A[b] + A[a] + A[c] <= W[1]) ans = 1;
        if (2 * A[c] + A[a] <= W[1] && 2 * A[b] + A[a] + A[c] <= W[0]) ans = 1;

        if (A[a] + A[b] + A[c] <= W[0] && 2 * A[a] + 2 * A[b] <= W[1]) ans = 1;
        if (A[a] + A[b] + A[c] <= W[1] && 2 * A[a] + 2 * A[b] <= W[0]) ans = 1;

        if (2 * A[a] + A[b] <= W[0] && 2 * A[a] + 2 * A[c] <= W[1]) ans = 1;
        if (2 * A[a] + A[b] <= W[1] && 2 * A[a] + 2 * A[c] <= W[0]) ans = 1;

        if (A[a] + A[c] <= W[0] && 3 * A[b] + A[a] + A[c] <= W[1]) ans = 1;
        if (A[a] + A[c] <= W[1] && 3 * A[b] + A[a] + A[c] <= W[0]) ans = 1;
    }

    cout << (ans ? "Yes" : "No") << '\n';
}
