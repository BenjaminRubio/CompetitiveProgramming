#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> e;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        e.resize(N);
        rep(i, N) cin >> e[i];

        sort(e.begin(), e.end());

        int g = 0, ans = 0;
        for (int p : e)
        {
            g++;
            if (g >= p) { ans++; g = 0; }
        }

        cout << ans << '\n';
    }
}