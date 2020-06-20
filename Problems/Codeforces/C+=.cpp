#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> n;

        if (a > b) swap(a, b);

        int x = max(a, b);

        int cnt = 0;
        while (n >= x)
        {
            if (cnt & 1) b += a;
            else a += b;
            x = max(a, b);
            cnt++;
        }

        cout << cnt << '\n';
    }
}