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

int T, N, a;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;

        vector<int> L;
        rep(_, N)
        {
            cin >> a;
            if (a == 1) L.push_back(a);
            else
            {
                while (L.back() != a - 1) L.pop_back();
                L.back()++;
            }
            rep(i, L.size()) cout << L[i] << (i < (L.size() - 1) ? "." : "");
            cout << '\n';
        }
    }
}
