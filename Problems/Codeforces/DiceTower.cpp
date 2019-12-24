#include <bits/stdc++.h>
using namespace std;

int T;
long long x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x;
        if (x % 14LL < 7LL && x % 14LL > 0 && x > 14LL)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}