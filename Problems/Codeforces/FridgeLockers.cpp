#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<par> vp;
typedef long long ll;

int T, n, m, a_;
vp a, edges;

int main()
{
    cin >> T;

    rep(t, T)
    {
        edges.clear();
        cin >> n >> m;

        int cost = 0;
        a.resize(n);
        rep(i, n)
        {
            cin >> a_;
            a[i] = {a_, i};
            cost += 2 * a_;
        }

        if (n <= 2 || m < n)
        {
            cout << -1 << '\n';
            continue;
        }

        rep(i, n)
        {
            if (i < n - 1)
                edges.push_back({i, i + 1});
            else
                edges.push_back({n - 1, 0});
        }

        sort(a.begin(), a.end());

        rep(i, m - n) edges.push_back({a[0].second,  a[1].second});
        cost += (m - n) * (a[0].first + a[1].first);

        cout << cost << '\n';
        for (par e : edges)
            cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
}