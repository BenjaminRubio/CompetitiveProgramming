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

int T, N, L, R, c;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> L >> R;

        multiset<int> sl, sr;
        rep(i, L) { cin >> c; sl.insert(c); }
        rep(i, R) { cin >> c; sr.insert(c); }

        if (L > R) swap(L, R), swap(sl, sr);

        stack<int> ss;
        for (int c : sl) if (sr.count(c)) ss.push(c), sr.erase(sr.find(c));
        while (!ss.empty()) sl.erase(sl.find(ss.top())), ss.pop();

        L = sl.size(), R = sr.size();

        int ans = 0;

        vi vr; for (int c : sr) vr.pb(c);
        int d = (R - L), c = 0, p = 0;
        while (c < d && p < R - 1)
        {
            if (vr[p] == vr[p + 1])
            {
                sr.erase(sr.find(vr[p]));
                sr.erase(sr.find(vr[p + 1]));
                c += 2, p += 2, ans++;
            }
            else p++;
        }
        L = sl.size(), R = sr.size();
        ans += R;

        cout << ans << '\n';
    }   
}
