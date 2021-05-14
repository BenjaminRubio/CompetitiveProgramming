#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, DP[1 << 25];;
pair<int, int> P[25], D[1 << 25];;

int dist(int i, int j)
{
    int dx = abs(P[i].ff - P[j].ff), dy = abs(P[i].ss - P[j].ss);
    return dx * dx + dy * dy;
}

int dp(int b)
{
    if (b == 0) return 0;
    if (DP[b] != -1) return DP[b];

    D[b] = {-1, -1};

    int i;
    rep(k, N) if (b & (1 << k)) { i = k; break; }

    D[b].ff = i;

    int ans = dp(b ^ (1 << i)) + 2 * dist(0, i + 1);
    for (int j = i + 1; j < N; j++) if (b & (1 << j))
    {
        int d = dist(0, i + 1) + dist(i + 1, j + 1) + dist(j + 1, 0);
        if ((dp(b ^ ((1 << i) | (1 << j))) + d) < ans)
        {
            ans = dp(b ^ ((1 << i) | (1 << j))) + d;
            D[b].ss = j;
        }
    }
    
    return DP[b] = ans;
}

int main()
{
    cin >> P[0].ff >> P[0].ss >> N;
    rep(i, N) cin >> P[i + 1].ff >> P[i + 1].ss;

    memset(DP, -1, sizeof DP);
    cout << dp((1 << N) - 1) << '\n';

    int b = (1 << N) - 1, i, j;
    while (b)
    {
        tie(i, j) = D[b];

        cout << 0 << ' ' << i + 1 << ' '; b ^= 1 << i;
        if (j != -1) { cout << j + 1 << ' '; b ^= 1 << j; }
    }
    cout << 0 << '\n';
}