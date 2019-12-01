#include <bits/stdc++.h>
using namespace std;

int mass;

int main()
{
    int ans = 0;
    while (cin >> mass)
    {
        while (mass)
        {
            mass = max(mass / 3 - 2, 0);
            ans += mass;
        }
    }
    cout << ans << '\n';
}