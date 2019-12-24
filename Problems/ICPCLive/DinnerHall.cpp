#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, h, m, s, in;
char e, sep;
set<tuple<int, int, int, char>> events;

int main()
{
    while (cin >> N)
    {
        if (N == 0)
            break;

        in = 0;
        rep(i, N)
        {
            cin >> h >> sep >> m >> sep >> s >> e;
            events.insert({h, m, s, e});

            if (e == 'E')
                in++;
        }

        int in_ = N / 2 - in;
        int count = 0;
        int ans = 0;
        int unk = 0;
        for (auto ev : events)
        {
            if (get<3>(ev) == 'E')
                count++;
            if (get<3>(ev) == 'X')
                count--;
            if (get<3>(ev) == '?')
            {
                if (unk < in_)
                    count++;
                else
                    count--;
                unk++;
            }
            ans = max(ans, count);
        }

        cout << ans << '\n';
        events.clear();
    }
}