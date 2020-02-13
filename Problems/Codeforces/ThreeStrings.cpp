#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string a, b, c;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> a >> b >> c;
        int n = a.size();

        bool pos = true;
        rep(i, n)
        {
            if (a[i] == b[i] and c[i] != a[i]) pos = false;
            if (a[i] != b[i] and c[i] != a[i] and b[i] != c[i]) pos = false;
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}