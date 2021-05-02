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

int T, N, X;
vi A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> X;

        A.resize(N); rep(i, N) cin >> A[i];
        sort(all(A));

        int s = 0, sw = 0;
        rep(i, N - 1)
        {
            s += A[i];
            if (s == X) swap(A[i], A[N - 1]), sw = 1;
        }
        s += A[N - 1];

        if (sw == 1 || s != X)
        {
            cout << "YES\n";
            rep(i, N) cout << A[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }   
}
