#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m, a;
priority_queue<pair<int, int>> q;
vector<int> c;

int main()
{
    cin >> n >> m;

    rep(i, n) rep(j, m)
    {
        cin >> a;
        q.push({a, i});
    }

    c.assign(n, 0);

    bool f = false;
    int i, j;
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();

        c[p.second]++;
        if (c[p.second] == m)
        {
            if (!f)
            {
                i = p.second;
                f = true;
            }
            else
            {
                j = p.second;
                break;
            }
        }
    }

    cout << i << ' ' << j << '\n';
}