#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, G, s, r;
vector<int> v;

int main()
{
    while (cin >> N >> G)
    {
        int ans = 0;
        v.resize(N);
        rep(i, N)
        {
            cin >> s >> r; v[i] = s - r;
            ans += (v[i] > 0 ? 3 : (!v[i] ? 1 : 0));
        }

        sort(v.rbegin(), v.rend());

        int i = -1;
        while (G && ++i < N)
        {
            if (v[i] == 0) G--, ans += 2;
            if (v[i] < 0 && G == -v[i]) G = 0, ans += 1;
            if (v[i] < 0 && G > -v[i]) G -= -v[i] + 1, ans += 3;
        }

        cout << ans << '\n';
    }
}