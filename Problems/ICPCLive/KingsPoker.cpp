#include <bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int a, b, c;

int main()
{
    while (cin >> a >> b >> c)
    {
        if (a == 0)
            break;

        if (a > b)
            swap(a, b);
        if (a > c)
            swap(a, c);
        if (b > c)
            swap(b, c);

        if (a == b && b == c)
        {
            if (a < 13)
                cout << a + 1 << ' ' << a + 1 << ' ' << c + 1 << '\n';
            else
                cout << "*\n";
        }
        else if (a == b)
        {
            if (c < 13)
                cout << a << ' ' << b << ' ' << c + 1 << '\n';
            else if (a < 13)
                cout << 1 << ' ' << a + 1 << ' ' << a + 1 << '\n';
            else
                cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
        }
        else if (b == c)
        {
            bool done = false;
            repx(i, a + 1, 14)
            {
                if (i != b)
                {
                    if (i < b)
                        cout << i << ' ' << b << ' ' << c << '\n';
                    else
                        cout << b << ' ' << c << ' ' << i << '\n';
                    done = true;
                    break;
                }
            }
            if (!done && b < 13)
                cout << 1 << ' ' << b + 1 << ' ' << b + 1 << '\n';
            else if (!done)
                cout << 1 << ' ' << 1 << ' ' << 1 << '\n';
        }
        else
            cout << 1 << ' ' << 1 << ' ' << 2 << '\n';
    }
}