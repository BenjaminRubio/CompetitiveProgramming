#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N, K;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        if (K % N == 0) cout << 0 << '\n';
        else cout << 2 << '\n';

        vector<vector<int>> ans(N, vector<int>(N, 0));
        int o = 0;
        while (K)
        {
            // cerr << "aaaa" << min(K, N) << '\n';
            int m = min(K, N);
            rep(i, m)
            {
                // cerr << i << ' ' << o << '\n';
                ans[i][(i + o) % N]++;
                K--;
            }
            o++;
        }

        rep(i, N)
        {
            rep(j, N) cout << ans[i][j];
            cout << '\n';
        }
    }
}