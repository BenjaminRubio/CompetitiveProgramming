#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, l, s;
vector<int> mins, maxs;

int main()
{
    cin >> n;

    long long ans = 0;
    int e = 0;

    rep(i, n)
    {
        cin >> l;
        int m = 1e7;
        int M = -1;

        bool extra = false;

        rep(j, l)
        {
            cin >> s;
            if (s > m)
                extra = true;
            m = min(m, s);
            M = max(M, s);
        }

        if (extra)
        {
            ans += 2 * (n - e) - 1;
            e++;
        }
        else
        {
            mins.push_back(m);
            maxs.push_back(M);
        }
    }

    sort(maxs.begin(), maxs.end());
    sort(mins.begin(), mins.end());

    int j = 0;
    rep(i, maxs.size())
    {
        while (j < maxs.size() && maxs[j] <= mins[i])
            j++;
        ans += (maxs.size() - j);
    }

    cout << ans << '\n';
}