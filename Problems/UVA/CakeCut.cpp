#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct Point
{
    ll x, y;
};

int n;
ll x, y;
vector<Point> pol;
vector<ll> areas;

int main()
{
    while (cin >> n)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        pol.resize(n);
        areas.resize(2 * n + 1);
        rep(i, n)
        {
            cin >> x >> y;
            pol[i] = Point({x, y});
        }
        rep(i, n + 1) pol.push_back(pol[i]);

        ll sum = 0;
        rep(i, 2 * n)
        {
            areas[i] = sum;
            sum += (pol[i].x + pol[i + 1].x) * (pol[i + 1].y - pol[i].y);
        }
        areas[2 * n] = sum;

        ll total_area = sum / 2LL;

        ll aux = LLONG_MAX;
        rep(k, n)
        {
            int i = k + 2;
            int j = k + n - 1;
            while (i < j)
            {
                int m = (i + j) >> 1;
                ll arista = (pol[m].x + pol[k].x) * (pol[k].y - pol[m].y);
                if (2LL * (areas[m] - areas[k] + arista) > total_area)
                    j = m;
                else
                    i = m + 1;
            }

            if (i == k + 2)
            {
                ll arista = (pol[i].x + pol[k].x) * (pol[k].y - pol[i].y);
                aux = min(aux, total_area - (areas[i] - areas[k] + arista));
            }
            else if (i == k + n - 1)
            {
                ll arista = (pol[i - 1].x + pol[k].x) * (pol[k].y - pol[i - 1].y);
                aux = min(aux, areas[i - 1] - areas[k] + arista);
            }
            else
            {
                ll arista1 = (pol[i].x + pol[k].x) * (pol[k].y - pol[i].y);
                ll arista2 = (pol[i - 1].x + pol[k].x) * (pol[k].y - pol[i - 1].y);
                ll area1 = areas[i] - areas[k] + arista1;
                ll area2 = areas[i - 1] - areas[k] + arista2;
                aux = min({aux, max(total_area - area1, area2)});
            }
        }
        
        cout << total_area - aux << ' ' << aux << '\n';
    }
}