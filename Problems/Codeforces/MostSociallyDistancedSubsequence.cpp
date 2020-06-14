#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, p;

int sgn(int x) { return x > 0 ? 1 : -1; }

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        int ls = 0, l;
        vector<int> ans;
        rep(i, N)
        {
            cin >> p;
            if (i && sgn(p - l) != ls) ans.push_back(l);
            if (i == N - 1) ans.push_back(p);
            if (i) ls = sgn(p - l);
            l = p;
        }

        cout << ans.size() << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}