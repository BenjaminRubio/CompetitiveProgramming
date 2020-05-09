#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        if (min(n, m) <= 1) cout << "YES\n";
        else if (max(n, m) == 2) cout << "YES\n";
        else cout << "NO\n"; 
    }
}