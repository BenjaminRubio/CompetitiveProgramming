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

int T, N;
vector<int> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N); rep(i, N) cin >> A[i];

        cout << 6 * (N / 2) << '\n';
        rep(i, N / 2)
        {
            cout << 1 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
            cout << 2 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
            cout << 2 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
            cout << 1 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
            cout << 2 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
            cout << 2 << ' ' << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
        }
    }
}
