#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int x, y, x_, y_;

int main()
{
    int H = 0, V = 0;
    set<pair<int, int>> p;
    set<pair<pair<int, int>, pair<int, int>>> s;

    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y >> x_ >> y_;
        if (x == x_) V++;
        if (y == y_) H++;

        p.emplace(x, y); p.emplace(x_, y_);
        s.emplace(mp(x, y), mp(x_, y_));
        s.emplace(mp(x_, y_), mp(x, y));
    }

    if (s.size() != 8 || p.size() != 4 || H != 2 || V != 2) cout << "NO\n";
    else cout << "YES\n";
}