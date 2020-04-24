#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, n, k;
vector<int> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        a.assign(n + 1, 0);

        int h, l = INT_MAX, l_ = INT_MAX;
        rep(i, n)
        {
            cin >> h;
            if (i and l > l_ and l > h) a[i - 1] = a[i - 2] + 1;
            else if (i > 1) a[i - 1] = a[i - 2];
            l_ = l;
            l = h;
        }
        if (l > l_ and l > h) a[n - 2] = a[n - 3] + 1;

        k -= 2;
        int t = INT_MIN;
        repx(i, 1, n - k + 1) if ((a[i + k - 1] - (i ? a[i - 1] : 0)) > t)
        {
            t = a[i + k - 1] - (i ? a[i - 1] : 0);
            l = i + 1;
        }

        cout << t + 1 << ' ' << l - 1 << '\n';
    }
}