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

int N, K, R; char ch;
int P[9];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;

    P[0] = 1;
    rep(i, 7) P[i + 1] = P[i] * 9;

    vector<vector<int>> C;

    unordered_map<int, int> m;
    m.reserve(1e7);

    rep(_, N)
    {
        cin >> ch;

        if (ch == 'C')
        {
            cin >> R;

            vector<int> a(8); int x;
            rep(i, R) { cin >> x; a[x - 1]++; }

            rep(i0, a[0] + 1) rep(i1, a[1] + 1) rep(i2, a[2] + 1) rep(i3, a[3] + 1) rep(i4, a[4] + 1) rep(i5, a[5] + 1) rep(i6, a[6] + 1) rep(i7, a[7] + 1)
            {
                int b = i0 + P[1] * i1 + P[2] * i2 + P[3] * i3 + P[4] * i4 + P[5] * i5 + P[6] * i6 + P[7] * i7;
                m[b]++;
            }

            C.pb(a);
        }

        if (ch == 'D')
        {
            int x;
            cin >> x; x--;

            vector<int> a = C[x];

            rep(i0, a[0] + 1) rep(i1, a[1] + 1) rep(i2, a[2] + 1) rep(i3, a[3] + 1) rep(i4, a[4] + 1) rep(i5, a[5] + 1) rep(i6, a[6] + 1) rep(i7, a[7] + 1)
            {
                int b = i0 + P[1] * i1 + P[2] * i2 + P[3] * i3 + P[4] * i4 + P[5] * i5 + P[6] * i6 + P[7] * i7;
                m[b]--;
            }
        }

        if (ch == 'J')
        {
            cin >> R;

            vector<int> a(8); int x;
            rep(i, R) { cin >> x; a[x - 1]++; }

            int b = a[0] + P[1] * a[1] + P[2] * a[2] + P[3] * a[3] + P[4] * a[4] + P[5] * a[5] + P[6] * a[6] + P[7] * a[7];

            cout << m[b] << '\n';
        }
    }
}
