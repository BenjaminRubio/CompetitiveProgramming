#include <bits/stdc++.h>
using namespace std;

int n, k, l, c, d, p, nl, np;

int main()
{
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drinks = k * l / nl;
    int limes = c * d;
    int salt = p / np;

    cout << min({drinks, limes, salt}) / n << '\n';
}