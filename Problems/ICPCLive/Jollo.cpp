#include <bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int a, b, c, x, y;
vector<pair<int, bool>> cards;
vector<bool> check;

int main()
{
    cards.resize(5);
    while (cin >> a >> b >> c >> x >> y)
    {
        if (a == 0)
            break;

        if (b > c)
            swap(b, c);
        if (a > c)
            swap(a, c);
        if (a > b)
            swap(a, b);
        if (x > y)
            swap(x, y);

        bool done = false;
        if ((x < a || x < b) && (y < b || y < c))
            cout << -1 << '\n';
        else if (x < b && c < y)
        {
            repx(i, c + 1, 53) if (i != y)
            {
                cout << i << '\n';
                done = true;
                break;
            }
            if (!done)
                cout << -1 << '\n';
        }
        else if (b < x && x < c && c < y)
        {
            repx(i, b + 1, 53) if (i != x && i != c && i != y)
            {
                cout << i << '\n';
                done = true;
                break;
            }
            if (!done)
                cout << -1 << '\n';
        }
        else if (x > c)
        {
            repx(i, 1, 53) if (i != a && i != b && i != c && i != x && i != y)
            {
                cout << i << '\n';
                done = true;
                break;
            }
            if (!done)
                cout << -1 << '\n';
        }
        else
        {
            repx(i, b + 1, 53) if (i != b && i != c && i != x && i != y)
            {
                cout << i << '\n';
                done = true;
                break;
            }
            if (!done)
                cout << -1 << '\n';
        }
    }
}