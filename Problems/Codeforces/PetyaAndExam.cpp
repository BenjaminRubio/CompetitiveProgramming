#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll M, n, T, a, b, easy;
vector<pair<ll, ll>> events;

int main()
{
    cin >> M;
    rep(m, M)
    {
        cin >> n >> T >> a >> b;

        easy = 0;
        events.resize(n);
        rep(i, n)
        {
            cin >> events[i].second;
            if (events[i].second == 0)
                easy++;
        }

        rep(i, n) cin >> events[i].first;

        sort(events.begin(), events.end());

        ll ans = 0;
        ll count = 0;
        ll i = 0;
        ll aux = 0;
        ll last = -1;
        for (auto e : events)
        {
            if (e.first != last && e.first - 1 >= count)
            {
                ll extra = e.first - 1 - count;
                ll easy_aux = min(extra / a, easy - aux);
                ll hard_aux = min((extra - easy_aux * a) / b, n - easy - (i - aux));
                ans = max(ans, i + easy_aux + hard_aux);
            }

            if (e.second == 0)
            {
                aux++;
                count += a;
            }
            else
                count += b;
            i++;
            last = e.first;
        }
        if (T >= count)
            ans = max(ans, n);

        cout << ans << '\n';
    }
}