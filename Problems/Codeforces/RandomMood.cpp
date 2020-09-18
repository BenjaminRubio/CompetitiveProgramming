#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N; double P;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> P;

    double ans = 1;
    while (N)
    {
        if (N & 1) ans = ans * (1 - P) + (1 - ans) * P;
        P = P * (1 - P) + (1 - P) * P;
        N >>= 1;
    }

    cout << ans << '\n';
}