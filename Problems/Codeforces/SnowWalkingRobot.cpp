#include <bits/stdc++.h>
using namespace std;

int q;
string s;
vector<int> c;

map<char, int> m = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
map<char, int> dx = {{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'L', 0}, {'R', 0}, {'U', 1}, {'D', -1}};
set<pair<int, int>> posiciones;

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> s;
        c.assign(4, 0);
        posiciones.clear();

        for (char ch : s)
        {
            c[m[ch]]++;
        }

        pair<int, int> pos = {0, 0};
        posiciones.insert({0, 0});

        bool able = true;

        for (char ch : s)
        {
            pos.first += dx[ch];
            pos.second += dy[ch];

            posiciones.insert(pos);
        }

        if (posiciones.size() == s.size() && pos == make_pair(0, 0))
        {
            cout << posiciones.size() << '\n';
            cout << s << '\n';
        }
        else
        {
            int x = min(c[0], c[1]);
            int y = min(c[2], c[3]);

            if (x == 0 && y > 0)
                y = 1;
            if (y == 0 && x > 0)
                x = 1;

            cout << 2 * x + 2 * y << '\n';

            for (int i = 0; i < x; i++)
                cout << 'L';
            for (int i = 0; i < y; i++)
                cout << 'U';
            for (int i = 0; i < x; i++)
                cout << 'R';
            for (int i = 0; i < y; i++)
                cout << 'D';
            cout << '\n';
        }
    }
}