#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;

int main()
{
    cin >> n;

    int x = 0;

    vector<pair<int, int>> ans;

    ans.emplace_back(x, 0); x++;
    ans.emplace_back(x, 0); x++;
    rep(i, n / 2)
    {
        ans.emplace_back(x, 1);
        ans.emplace_back(x, 0);
        ans.emplace_back(x, -1); x++;
        ans.emplace_back(x, 1);
        ans.emplace_back(x, 0);
        ans.emplace_back(x, -1); x++;
        ans.emplace_back(x, 0); x++;
    }
    if (n & 1)
    {
        ans.emplace_back(x, 3);
        ans.emplace_back(x, 2); 
        ans.emplace_back(x, 1);
        ans.emplace_back(x, 0);
        ans.emplace_back(x, -1); x++;
        ans.emplace_back(x, 0);
        ans.emplace_back(x, -1);

        ans.emplace_back(0, 1);
        ans.emplace_back(0, 2);
        ans.emplace_back(0, 3);
    }
    else
    {
        ans.emplace_back(x, 3);
        ans.emplace_back(x, 2); 
        ans.emplace_back(x, 1);
        ans.emplace_back(x, 0); x++;
        ans.emplace_back(0, 1);
        ans.emplace_back(0, 2);
        ans.emplace_back(0, 3);
    }
    
    int p = 0;
    while (p + 1 < x - 1) { ans.emplace_back(p + 1, 3); p++; }

    cout << ans.size() << '\n';
    for (auto e : ans) cout << e.first << ' ' << e.second << '\n';
}