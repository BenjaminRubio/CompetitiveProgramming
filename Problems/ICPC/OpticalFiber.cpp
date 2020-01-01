#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    int x, y;
    double dist2(Point &p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int N, C, x, y;
vector<vector<Point>> cities;
map<string, int> city_index;
vector<vector<int>> g, g_;
vector<int> parent;
vector<bool> visited;
string name, n1, n2;

double DP[1000][50];

double dp(int index, int city)
{
    if (DP[index][city] != 0)
        return DP[index][city];

    double ans = DBL_MAX;
    rep(i, cities[index].size())
    {
        double ans_ = 0;
        if (index > 0)
            ans_ = cities[index][i].dist2(cities[parent[index]][city]);
        for (int j : g[index])
            ans_ += dp(j, i);
        ans = min(ans, ans_);
    }

    return DP[index][city] = ans;
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            g_[u].push_back(v);
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(1);

    while (cin >> N)
    {
        if (N == 0)
            break;

        cities.assign(N, {});
        city_index.clear();
        rep(i, N)
        {
            cin >> name >> C;
            city_index[name] = i;

            cities[i].resize(C);
            rep(j, C)
            {
                cin >> x >> y;
                cities[i][j] = {x, y};
            }
        }

        g.assign(N, {});
        rep(i, N - 1)
        {
            cin >> n1 >> n2;
            g[city_index[n1]].push_back(city_index[n2]);
            g[city_index[n2]].push_back(city_index[n1]);
        }

        g_.assign(N, {});
        visited.assign(N, false);
        parent.resize(N);
        dfs(0);
        swap(g, g_);

        memset(DP, 0, sizeof DP);

        cout << dp(0, 0) << '\n';
    }
}