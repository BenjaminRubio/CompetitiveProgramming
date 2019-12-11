#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

set<int> s;
int ang;

int main()
{
    rep(i, 24) rep(j, 60)
    {
        int p1 = j;
        int p2 = 5 * i + j / 12;

        s.insert(min(6 * abs(p1 - p2), 6 * (p1 + p2 - 60)));
    }

    while (cin >> ang)
    {
        if (s.count(ang))
            cout << "Y\n";
        else
            cout << "N\n";
    }
}