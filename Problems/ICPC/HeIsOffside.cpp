#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int A, D, x;

int main()
{
    while (cin >> A >> D)
    {
        if (A == 0 && D == 0)
            break;

        int a = 1e5;
        rep(i, A)
        {
            cin >> x;
            a = min(a, x);
        }

        int c = 0;
        rep(i, D)
        {
            cin >> x;
            c += (a < x);
        }

        if (c > D - 2)
            cout << "Y\n";
        else
            cout << "N\n";
    }
}