#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, x;
set<int> s;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;

        rep(i, n)
        {
            cin >> x;
            s.insert(x);
        }

        cout << s.size() << '\n';
        s.clear();
    }
}