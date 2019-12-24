#include <bits/stdc++.h>
using namespace std;

long long x, y, a, b, c, d;

int main()
{
    cin >> x >> y >> a >> b >> c >> d;

    long long g = __gcd(x, y);
    
    if (g > 1LL)
    {
        long long dx = x / g;
        long long dy = y / g;

        if (dx < a || dy < b)
        {
            cout << "No\n";
            cout << dx << ' ' << dy << '\n';
        }
        else if (x - dx > c || y - dy > d)
        {
            cout << "No\n";

            long long delta;
            delta = ((c / dx) + 1LL);
            delta = min(delta, ((d / dy) + 1LL));
            
            cout << dx * delta << ' ' << dy * delta << '\n';
        }
        else
            cout << "Yes\n";
    }
    else
        cout << "Yes\n";
}