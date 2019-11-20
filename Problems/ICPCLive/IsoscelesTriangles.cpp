#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
typedef vector<pair<ll, ll>> vp;

int n, x, y;
vp coords;
vector<vector<ll>> distances;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n)
    {
        if (n == 0)
            break;

        coords.resize(n);
        rep(i, n)
        {
            cin >> x >> y;
            coords[i] = {x, y};
        }

        distances.assign(n, vector<ll>(n, 0));
        rep(i, n) rep(j, n)
            distances[i][j] = (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first) +
                              (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second);

        ll counter = 0;
        rep(i, n)
        {
            sort(distances[i].begin(), distances[i].end());

            ll last = -1;
            ll accum = 0;
            rep(j, n)
            {
                if (distances[i][j] != last)
                {
                    counter += accum * (accum - 1) / 2;
                    accum = 1;
                }
                else
                {
                    accum++;
                }
                last = distances[i][j];
            }
            counter += accum * (accum - (ll)1) / (ll)2;
        }

        cout << counter << '\n';
    }
}