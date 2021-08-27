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

int T, K; char A, B;
string S, ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, vector<char>> G;
map<char, bool> V;
map<char, int> C;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    rep(tt, T)
    {
        cin >> S >> K;

        G.clear();
        rep(_, K)
        {
            cin >> A >> B;
            G[B].pb(A);
        }

        int ans = INT_MAX;
        for (char c : ALF)
        {
            V.clear(), C.clear();

            queue<pair<char, int>> q; q.emplace(c, 0);
            V[c] = 1, C[c] = 0;
            while (!q.empty())
            {
                char cc = q.front().ff; int w = q.front().ss; q.pop();
                for (char ccc : G[cc]) if (!V[ccc])
                {
                    V[ccc] = 1, C[ccc] = w + 1;
                    q.emplace(ccc, w + 1);
                }
            }

            int aux = 0;
            for (char cc : S)
            {
                if (!V[cc]) { aux = INT_MAX; break; }
                aux += C[cc];
            }

            ans = min(ans, aux);
        }

        cout << "Case #" << tt + 1 << ": " << (ans != INT_MAX ? ans : -1);
        if (tt < T - 1) cout << '\n';
    }
}
