#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, K, x, y; 
vector<pair<ll, ll>> V;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K; V.clear();

        rep(i, N)
        {
            cin >> x >> y;
            V.emplace_back(x, y);
        }

        int ans = -1;
        rep(i, N)
        {
            int c = 0;
            rep(j, N)
            {
                ll dx = V[i].ff - V[j].ff;
                ll dy = V[i].ss - V[j].ss;

                if (abs(dx) + abs(dy) <= K) c++;
            }

            if (c == N) ans = 1;
        }

        cout << ans << '\n';
    }
}