#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

int main()
{
    cin >> N;

    int ans = 1;
    while (((ans * (ans + 1)) / 2) <= N) ans++;
    ans--;

    cout << ans << '\n';
    rep(i, ans - 1) cout << i + 1 << ' ';
    cout << ans + (N - ((ans * (ans + 1)) / 2)) << '\n';
}
