#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        set<int> s;
        rep(i, n)
        {
            cin >> a;
            s.insert(((a + i) % n + n) % n);
        }

        if (s.size() == n) cout << "YES\n";
        else cout << "NO\n";
    }
}