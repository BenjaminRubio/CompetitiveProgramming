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

int T, N, M;
char G[50][50];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        rep(i, N) rep(j, M) cin >> G[i][j];

        int flag = 1;
        rep(i, N) rep(j, M)
        {
            if (G[i][j] != '.')
            {
                if ((G[i][j] == 'W' && !((i + j) & 1)) || (G[i][j] == 'R' && ((i + j) & 1))) flag = 1;
                if ((G[i][j] == 'R' && !((i + j) & 1)) || (G[i][j] == 'W' && ((i + j) & 1))) flag = 2;
            }
        }

        if (flag == 1)
        {
            bool flagg = 1;
            rep(i, N) rep(j, M)
            {
                if (((i + j) & 1) == 0 && G[i][j] == 'R') flagg = 0;
                if (((i + j) & 1) == 1 && G[i][j] == 'W') flagg = 0;
            }
            if (!flagg) { cout << "NO\n"; continue; }
            cout << "YES\n";
            rep(i, N)
            {
                rep(j, M) cout << (((i + j) & 1) ? 'R' : 'W');
                cout << '\n';
            }
        }
        if (flag == 2)
        {
            bool flagg = 1;
            rep(i, N) rep(j, M)
            {
                if (((i + j) & 1) == 0 && G[i][j] == 'W') flagg = 0;
                if (((i + j) & 1) == 1 && G[i][j] == 'R') flagg = 0;
            }
            if (!flagg) { cout << "NO\n"; continue; }
            cout << "YES\n";
            rep(i, N)
            {
                rep(j, M) cout << (((i + j) & 1) ? 'W' : 'R');
                cout << '\n';
            }
        }
    }   
}
