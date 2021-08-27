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

int T;
string S;
string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
set<char> VOC = {'A', 'E', 'I', 'O', 'U'}; 

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(tt, T)
    {
        cin >> S;

        int ans = INT_MAX;
        for (char c : ALF)
        {
            int aux = 0;
            for (char cc : S) if (c != cc)
            {
                if (VOC.count(c) && VOC.count(cc)) aux += 2;
                if (!VOC.count(c) && VOC.count(cc)) aux += 1;
                if (VOC.count(c) && !VOC.count(cc)) aux += 1;
                if (!VOC.count(c) && !VOC.count(cc)) aux += 2;
            }
            ans = min(ans, aux);
        }

        cout << "Case #" << tt + 1 << ": " << ans;
        if (tt < T - 1) cout << '\n';
    }
}
