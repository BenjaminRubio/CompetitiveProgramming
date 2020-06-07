#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, x;
vector<int> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        a.resize(n);
        rep(i, n) cin >> a[i];

        bool on = false, off = false;
        rep(i, n)
        {
            cin >> x;
            if (x) on = true;
            else off = true;
        }

        if (on && off) cout << "Yes\n";
        else
        {
            bool flag = true;
            rep(i, n) if (i && a[i] < a[i - 1]) flag = false;

            if (flag) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}