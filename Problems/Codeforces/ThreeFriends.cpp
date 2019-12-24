#include <bits/stdc++.h>
using namespace std;

int q, a, b, c;

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> a >> b >> c;
        cout << max(abs(a - b) + abs(b - c) + abs(c - a) - 4, 0) << '\n';
    }
}