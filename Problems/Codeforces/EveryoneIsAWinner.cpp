#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef vector<int> vi;

int T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        set<int> ans = {0, 1};
        rep(i, floor(sqrt(n)))
        {
            ans.insert(n / (i + 1));
            ans.insert(i + 1);
        }

        cout << ans.size() << '\n';
        for (int r : ans)
            cout << r << ' ';
        cout << '\n';
    }
}