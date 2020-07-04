#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, N, R;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> R;

        if (R < N) cout << R * (R + 1ll) / 2ll << '\n';
        else cout << N * (N - 1ll) / 2ll + 1ll << '\n';
    }
}