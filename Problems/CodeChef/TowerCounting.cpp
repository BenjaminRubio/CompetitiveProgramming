#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int T, N;
double H;
vector<pair<pair<double, int>, pair<int, double>>> O;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> H >> N;

        O.resize(N);
        rep(i, N)
        {
            cin >> O[i].ss.ff >> O[i].ff.ff >> O[i].ss.ss;
            O[i].ff.ss = i;
        }

        sort(O.begin(), O.end());

        vector<int> ans(N, 0);
        double p1, p2, p, x, y;
        rep(i, N)
        {
            x = O[i].ff.ff, y = O[i].ss.ss, p1 = -1e10, p2 = 1e10;
            repx(j, i + 1, N)
            {
                if (O[j].ff.ff == x) { ans[O[i].ff.ss]++, ans[O[j].ff.ss]++; continue; }
                p = (O[j].ss.ss - y) / (O[j].ff.ff - x);
                if (p > p1 && p < p2) ans[O[i].ff.ss]++, ans[O[j].ff.ss]++;
                if (O[j].ss.ff == 0) p1 = max(p1, p);
                if (O[j].ss.ff == 1) p2 = min(p2, p);
            }
        }

        rep(i, N) cout << ans[i] << ' ';
        cout << '\n';
    }
}