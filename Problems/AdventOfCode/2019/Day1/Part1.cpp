#include <bits/stdc++.h>
using namespace std;

int mass;

int main()
{
    int ans = 0;
    while (cin >> mass)
    {
        ans += mass / 3 - 2;
    }
    cout << ans << '\n';
}