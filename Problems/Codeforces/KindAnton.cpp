#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<bool> p, m;
vector<int> a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        p.assign(n, false); m.resize(n, false);
        a.resize(n);
        rep(i, n - 1)
        {
            cin >> a[i];
            if (a[i] == -1) m[i + 1] = true;
            else m[i + 1] = m[i];
            if (a[i] == 1) p[i + 1] = true;
            else p[i + 1] = p[i];
        }
        cin >> a[n - 1];

        b.resize(n);
        rep(i, n) cin >> b[i];
        bool flag = true;
        rep(i, n)
        {
            if (b[n - i - 1] > a[n - i - 1] and !p[n - i - 1]) flag = false;
            if (b[n - i - 1] < a[n - i - 1] and !m[n - i - 1]) flag = false;
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}