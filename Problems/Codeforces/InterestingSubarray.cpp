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

        bool done = false;
        rep(i, n)
        {
            if (i < n - 1 && abs(a[i] - a[i + 1]) > 1)
            {
                cout << "YES" << '\n';
                cout << i + 1 << ' ' << i + 2 << '\n';
                done = true;
                break;
            }
        }

        if (!done)
            cout << "NO\n";
    }
}