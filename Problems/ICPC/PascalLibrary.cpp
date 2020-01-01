#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, d, x;
vector<int> c;

int main()
{
    while (cin >> n >> d)
    {
        if (n == 0 && d == 0)
            break;

        c.assign(n, 0);

        rep(i, d) rep(j, n)
        {
            cin >> x;
            if (x)
                c[j]++;
        }

        rep(i, n) if (c[i] == d)
        {
            cout << "yes\n";
            goto next;
        }

        cout << "no\n";

    next:
        continue;
    }
}