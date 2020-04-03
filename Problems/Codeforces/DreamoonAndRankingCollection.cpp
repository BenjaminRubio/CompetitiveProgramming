#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, x, a;
vector<bool> p;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> x;

        p.assign(101, false);
        rep(i, n)
        {
            cin >> a; a--;
            p[a] = true;
        }

        int v = 0;
        rep(i, 100)
        {
            v++;
            if (!x and !p[i]) { v--; break; }
            if (!p[i]) x--;
        }
        v += x;

        cout << v << '\n';
    }
}