#include <bits/stdc++.h>
using namespace std;

int C, B, P, c, b, p;

int main()
{
    while (cin >> C >> B >> P)
    {
        cin >> c >> b >> p;

        cout << max(c - C, 0) + max(b - B, 0) + max(p - P, 0) << '\n';
    }
}