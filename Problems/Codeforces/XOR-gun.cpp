#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> A;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    if (N > 100) { cout << 1 << '\n'; return 0; }

    int ans = INT_MAX;
    rep(p, N - 1)
    {
        int i = p, j = p + 1;
        int x1 = 0, x2 = 0;
        rep(x, i + 1)
        {
            x1 ^= A[i - x];
            x2 = 0;
            rep(y, N - j)
            {
                x2 ^= A[j + y];

                if (x1 > x2) ans = min(ans, x + y);
            }
        }
    }

    if (ans != INT_MAX) cout << ans << '\n';
    else cout << -1 << '\n';
}