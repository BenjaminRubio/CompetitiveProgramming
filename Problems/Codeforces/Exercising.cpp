#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, c, d, x, y, lx, hx, ly, hy;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> lx >> ly >> hx >> hy;

        if ((b - a >= 0 and hx - x >= b - a) or (b - a <= 0 and x - lx >= a - b))
        {
            if ((d - c >= 0 and hy - y >= d - c) or (d - c <= 0 and y - ly >= c - d))
            {
                if (!(a + b)) if (c + d and hy - ly) { cout << "Yes\n"; continue; }
                if (!(c + d)) if (a + b and hx - lx) { cout << "Yes\n"; continue; }
                if (a + b and hx - lx) if (c + d and hy - ly) { cout << "Yes\n"; continue; }
            }
        }

        cout << "No\n";
    }
}