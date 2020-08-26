#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int x, y, x_, y_;

int main()
{
    int H = 0, V = 0;
    set<pair<int, int>> p;
    set<pair<pair<int, int>, pair<int, int>>> s;

    cin >> x >> y >> x_ >> y_;

    if (x == x_ && y == y_) { cout << "NO\n"; return 0; }
    if (x == x_) V++;
    if (y == y_) H++;

    p.emplace(x, y); p.emplace(x_, y_);
    s.emplace(mp(x, y), mp(x_, y_));
    s.emplace(mp(x_, y_), mp(x, y));

    if (s.size() < 2) { cout << "NO\n"; return 0; }

    cin >> x >> y >> x_ >> y_;
    
    if (x == x_ && y == y_) { cout << "NO\n"; return 0; }
    if (x == x_) V++;
    if (y == y_) H++;

    p.emplace(x, y); p.emplace(x_, y_);
    s.emplace(mp(x, y), mp(x_, y_));
    s.emplace(mp(x_, y_), mp(x, y));

    if (s.size() < 4) { cout << "NO\n"; return 0; }

    cin >> x >> y >> x_ >> y_;
    
    if (x == x_ && y == y_) { cout << "NO\n"; return 0; }
    if (x == x_) V++;
    if (y == y_) H++;

    p.emplace(x, y); p.emplace(x_, y_);
    s.emplace(mp(x, y), mp(x_, y_));
    s.emplace(mp(x_, y_), mp(x, y));

    if (s.size() < 6) { cout << "NO\n"; return 0; }

    cin >> x >> y >> x_ >> y_;
    
    if (x == x_ && y == y_) { cout << "NO\n"; return 0; }
    if (x == x_) V++;
    if (y == y_) H++;

    p.emplace(x, y); p.emplace(x_, y_);
    s.emplace(mp(x, y), mp(x_, y_));
    s.emplace(mp(x_, y_), mp(x, y));

    if (s.size() < 8) { cout << "NO\n"; return 0; }

    if (p.size() != 4 || H != 2 || V != 2) { cout << "NO\n"; return 0; }

    cout << "YES\n";
}