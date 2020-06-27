#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll xb, yb, x_1, y_1, x_2, y_2, x_, y_, m;

int main()
{
    cin >> xb >> yb >> x_1 >> y_1 >> x_2 >> y_2;

    ll g = __gcd(xb, yb);

    if (g == 1) { cout << "Yes\n"; return 0; }

    x_ = xb / g, y_ = yb / g;
    if (x_ < x_1 || y_ < y_1 || x_ > x_2 || y_ > y_2)
    { cout << "No\n" << x_ << ' ' << y_ << '\n'; return 0; }
    m = min(x_2 / x_, y_2 / y_) + 1, x_ *= m, y_ *= m;
    if (m < g && (x_ < x_1 || y_ < y_1 || x_ > x_2 || y_ > y_2))
    { cout << "No\n" << x_ << ' ' << y_ << '\n'; return 0; }
    cout << "Yes\n";
}