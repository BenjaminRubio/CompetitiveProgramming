#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

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

int T, N, u;
vector<vl> U, S;
vl A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        U.assign(N, {});
        rep(i, N)
        {
            cin >> u; u--;
            U[u].pb(i);
        }

        A.resize(N);
        rep(i, N) cin >> A[i];

        rep(i, N) rep(j, U[i].size()) U[i][j] = A[U[i][j]];
        rep(i, N) sort(U[i].rbegin(), U[i].rend());

        S.assign(N, {});
        rep(i, N)
        {
            S[i].assign(U[i].size() + 1, 0);
            rep(j, U[i].size()) S[i][j + 1] = S[i][j] + U[i][j];
        }

        set<int> s;
        rep(i, N) s.insert(i);
        rep(k, N + 1) if (k)
        {
            ll ans = 0;
            stack<int> ss;
            for (int i : s)
            {
                ans += S[i][(int)U[i].size() - ((int)U[i].size() % k)];
                if ((int)U[i].size() == ((int)U[i].size() % k)) ss.push(i);
            }
            cout << ans << ' ';
            while (!ss.empty()) { s.erase(ss.top()); ss.pop(); }
        }
        cout << '\n';
    }
}
