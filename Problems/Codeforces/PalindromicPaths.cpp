#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
vector<vector<int>> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        A.assign(N, vector<int>(M));
        rep(i, N) rep(j, M) cin >> A[i][j];

        int ans = 0;
        rep(k, (N + M - 1) / 2)
        {
            // cerr << k << '\n';
            int on = 0, off = 0;
            int j = k, i = 0;
            if (k >= M) j = M - 1, i = k - j;
            while (j >= 0 && i < N)
            {
                if (A[i][j]) on++;
                else off++;
                if (A[N - i - 1][M - j - 1]) on++;
                else off++;
                i++, j--;
            }

            // cerr << on << ' ' << off << '\n';

            ans += min(on, off);
        }

        cout << ans << '\n';
    }
}