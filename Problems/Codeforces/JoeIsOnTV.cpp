#include <bits/stdc++.h>
using namespace std;

int n;
bool DP1[100010];
double DP[100010];

double dp(int i)
{
    if (i == 1) return 1;
    if (i <= 0) return 0;

    if (DP1[i])
        return DP[i];

    int l = 1;
    int r = i;
    while (l < r) {
        int t = (r - l) / 3.0;
        int m1 = l + t;
        int m2 = r - t;
        double v1 = (double) m1 / (double) i + dp(i - m1);
        double v2 = (double) m2 / (double) i + dp(i - m2);

        if (v1 < v2)
            l = m1 + 1;
        else if(v2 < v1)
            r = m2 - 1;
        else
            l = m1, r = m2;
    }

    DP1[i] = true;
    return DP[i] = (double) l / (double) i + dp(i - l);
}

int main()
{
    cin >> n;

    memset(DP1, false, sizeof DP1);

    cout << dp(n) << '\n';
}