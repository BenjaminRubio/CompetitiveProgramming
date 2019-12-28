#include <bits/stdc++.h>
using namespace std;

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

        check.assign(5, false);

        cards[0] = {a, false};
        cards[1] = {b, false};
        cards[2] = {c, false};
        cards[3] = {x, true};
        cards[4] = {y, true};

        sort(cards.begin(), cards.end());

        int count = 0;
        int ind;
        for (int i = 0; i < 10; i++)
        {
            if ((count == 1 || count == 3) && !cards[i % 5].second)
            {
                count++;
                check[i % 5] = true;
            }
            else if ((count == 0 || count == 2) && cards[i % 5].second)
            {
                count++;
                check[i % 5] = true;
            }
            else if (count == 4 || !check[i % 5])
            {
                ind = i % 5;
                break;
            }
        }

        bool done = false;
        for (int i = 1; i <= 52; i++)
        {
            if (!done && i > cards[ind].first && i != a && i != b && i != c && i != x && i != y)
            {
                cout << i << '\n';
                done = true;
            }
        }
        if (!done)
            cout << -1 << '\n';
    }
}