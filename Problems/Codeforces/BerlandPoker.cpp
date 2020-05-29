#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m, k;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;

        int M = min(m, n / k);
        int r = (m - M) / (k - 1) + bool((m - M) % (k - 1));
        cout << M - r << '\n';
    }
}