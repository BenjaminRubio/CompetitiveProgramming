#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        a.resize(n);
        rep(i, n) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = n - 1;
        while (ans >= 0 && a[ans] > ans + 1) ans--;

        cout << ans + 2 << '\n';
    }
}