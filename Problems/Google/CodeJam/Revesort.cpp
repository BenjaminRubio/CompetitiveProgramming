#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
vector<int> L;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> N;

        L.resize(N);
        rep(i, N) cin >> L[i];

        int ans = 0;
        rep(i, N - 1)
        {
            int p = -1;
            repx(j, i, N) if (L[j] == i + 1) { p = j; break; }

            ans += p - i + 1;
            vector<int> L_ = L;
            repx(j, i, p + 1) L_[j] = L[p - (j - i)];

            L = L_;
        }

        cout << ans << '\n';
    }
}