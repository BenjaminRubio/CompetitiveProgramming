#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

int main()
{
    cin >> N;

    int ans = 0;
    while (N)
    {
        ans <<= 1;
        if (N & 1) ans++;
        N >>= 1;
    }

    cout << ans << '\n';
}