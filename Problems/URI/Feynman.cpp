#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

int main()
{
    while (cin >> N && N)
    {
        int ans = 0;
        rep(i, N) ans += (i + 1) * (i + 1);

        cout << ans << '\n';
    }
}