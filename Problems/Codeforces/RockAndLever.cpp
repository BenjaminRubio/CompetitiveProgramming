#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a;
vector<long long> C;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        C.assign(30, 0);
        rep(i, N)
        {
            cin >> a;
            int m = 0;
            rep(j, 31) if (a & (1 << j)) m = j;
            C[m]++;
        }

        long long ans = 0;
        rep(i, 30) ans += C[i] * (C[i] - 1ll) / 2ll;

        cout << ans << '\n';
    }
}