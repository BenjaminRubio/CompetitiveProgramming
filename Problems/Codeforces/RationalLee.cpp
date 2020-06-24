#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K, w;
vector<int> A, W;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        A.resize(N); W.clear();
        rep(i, N) cin >> A[i];
        int ones = 0;
        rep(i, K)
        {
            cin >> w;
            if (w == 1) ones++;
            else W.push_back(w);
        }

        sort(A.begin(), A.end());
        sort(W.rbegin(), W.rend());

        ll ans = 0, i = 0, f = N - 1;

        while (ones--) ans += 2 * A[f--];

        for (int w : W)
        {
            ans += A[f];
            if (w == 1) ans += A[f];
            f--;
            if (w > 1) ans += A[i], i += w - 1;
        }
        cout << ans << '\n';
    }
}