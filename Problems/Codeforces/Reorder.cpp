#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M, x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        int ans = 0;
        rep(i, N) { cin >> x; ans += x; }

        cout << (ans == M ? "YES\n" : "NO\n");
    }
}