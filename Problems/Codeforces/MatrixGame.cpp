#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m, x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        vector<bool> r(n, 0), c(m, 0);
        rep(i, n) rep(j, m)
        {
            cin >> x;
            if (x) r[i] = 1, c[j] = 1;
        }

        int cntr = 0, cntc = 0;
        rep(i, n) if (!r[i]) cntr++;
        rep(i, m) if (!c[i]) cntc++;

        x = min(cntr, cntc);

        if (x & 1) cout << "Ashish\n";
        else cout << "Vivek\n";
    }
}