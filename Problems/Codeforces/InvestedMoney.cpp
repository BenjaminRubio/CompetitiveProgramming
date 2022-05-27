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

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

string T, days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int t, N, D;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T >> N;

    rep(i, 7) if (days[i] == T) t = i;

    int d = (t + 30) % 7;

    int ans = 30;
    if (d == 5) ans += 2;
    if (d == 6) ans += 1;
    rep(_, N)
    {
        cin >> D;

        if (D == 0) continue;

        d = ((t - D) % 7 + 7) % 7;

        while (D > 30)
        {
            if (d == 0 && D >= 91) D %= 91;
            else if (d == 0) D -= 30, d = 2;
            else if (d == 1) D -= 30, d = 3;
            else if (d == 2 && D >= 91) D %= 91;
            else if (d == 2) D -= 30, d = 4;
            else if (d == 3) D -= 32, d = 0;
            else if (d == 4 && D >= 91) D %= 91;
            else if (d == 4) D -= 31, d = 0;
        }

        if (D == 0) { ans = 0; break; }

        int aux = 30 - D;
        d = (t + (30 - D)) % 7;
        if (d == 5) aux += 2;
        if (d == 6) aux += 1;

        ans = min(ans, aux);
    }

    cout << ans << '\n';
}
