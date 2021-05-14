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

int T, G; string S;
string P[6][20];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> G >> S;

        rep(i, 6) rep(j, 20) cin >> P[i][j];

        bool flag = 1;
        rep(y, G + 1)
        {
            int x = G - y;

            int i = 0, j = 0;
            set<string> ss;
            while (ss.size() < x)
            {
                if (!ss.count(P[i][j])) ss.insert(P[i][j]);
                if (i == 4) i = 0, j++;
                else i++;
            }

            i = 0;
            while (ss.size() < G)
            {
                if (!ss.count(P[5][i])) ss.insert(P[5][i]);
                i++;
            }

            if (!ss.count(S))
            {
                flag = 0;
                cout << y << '\n';
                break;
            }
        }

        if (flag) cout << "ADVANCED!\n";
    }
}
