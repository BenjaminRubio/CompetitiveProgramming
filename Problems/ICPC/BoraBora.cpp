#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef pair<int, int> par;

int P, M, N, f;
char s;
par top;
queue<par> deck;
vector<multiset<par>> hand(10);

int main()
{
    while (cin >> P >> M >> N)
    {
        if (P == 0) break;

        rep(i, N)
        {
            cin >> f >> s;
            deck.push({f, s});
        }

        rep(i, P) rep(_, M)
        {
            hand[i].insert(deck.front());
            deck.pop();
        }

        top = deck.front(); deck.pop();

        int d = 1, t = 0;
        bool done = false, re = false;
        while (true)
        {
            if (t < 0) t += P;
            if (t > P - 1) t -= P;
            
            if (!done and top.ff == 12)
            {
                d *= -1;
                done = true;
            }

            if (!done and top.ff == 7)
            {
                hand[t].insert(deck.front());
                deck.pop();
                hand[t].insert(deck.front());
                deck.pop();
                done = true;
                t += d;
                continue;
            }

            if (!done and top.ff == 1)
            {
                hand[t].insert(deck.front());
                deck.pop();
                done = true;
                t += d;
                continue;
            }

            if (!done and top.ff == 11)
            {
                done = true;
                t += d;
                continue;
            }

            par card;
            bool can = false;
            for (par it : hand[t])
            {
                if (it.ff == top.ff or it.ss == top.ss)
                {
                    can = true;
                    card = it;
                }
            }

            if (can)
            {
                top = card;
                done = false;
                auto it = hand[t].lower_bound(card);
                hand[t].erase(it);

                if (!done and top.ff == 12)
                {
                    d *= -1;
                    done = true;
                }

                if (hand[t].empty())
                {
                    cout << t + 1 << '\n';
                    break;
                }
            }
            else if (!re)
            {
                hand[t].insert(deck.front());
                deck.pop();
                re = true;
                continue;
            }

            t += d;
            re = false;
        }

        while (!deck.empty()) deck.pop();
        rep(i, P) hand[i].clear();
    }
}
