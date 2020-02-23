#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, c;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> a >> b >> c;

        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (b < c) swap(b, c);

        int ans = 0;

        if (a) ans++, a--;
        if (b) ans++, b--;
        if (c) ans++, c--;

        if (a and b) ans++, a--, b--;
        if (a and c) ans++, a--, c--;
        if (b and c) ans++, b--, c--;

        if (a and b and c) ans++;

        cout << ans << '\n';
    }
}