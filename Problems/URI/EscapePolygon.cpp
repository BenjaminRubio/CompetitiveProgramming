#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef vector<int> vi;
typedef long long ll;

struct Point
{
    ll x, y;
    Point operator-(const Point &p) const
    {
        return {x - p.x, y - p.y};
    }
    ll cross (const Point &p) const
    {
        return x * p.y - y * p.x;
    }
};

ll memo[100001][4];
ll choose(int n, int k)
{
    ll &ans = memo[n][k];
    if (ans != -1)
        return ans;
    if (k == 0)
        return ans = 1;
    if (n == k)
        return ans = 1;
    if (n < k)
        return ans = 0;
    return ans = (choose(n - 1, k) + choose(n - 1, k - 1));
}

int N, x, y;
vector<Point> pol;

int main()
{
    cin >> N;

    pol.resize(N);
    rep(i, N)
    {
        cin >> x >> y;
        pol[i] = {x, y};
    }
    rep(i, N) pol.push_back(pol[i]);

    memset(memo, -1, sizeof memo);

    ll count = choose(N, 3);

    int j = 0;
    rep(i, N)
    {
        while ((pol[i + 1] - pol[i]).cross(pol[j + 1] - pol[j]) >= 0)
            j++;
        // cerr << i << ' ' << j << '\n';
        count -= choose(j - i - 1, 2);
    }

    cout << count << '\n';
}