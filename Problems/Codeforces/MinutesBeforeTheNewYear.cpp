#include <bits/stdc++.h>
using namespace std;

int T, h, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> h >> m;

        if (m)
            cout << (23 - h) * 60 + (60 - m) << '\n';
        else
            cout << (24 - h) * 60 << '\n';
    }
}