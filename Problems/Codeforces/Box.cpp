#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;

int T, n, q;
vi counter;
vi p;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n;

        p.assign(n, -1);
        counter.assign(n + 1, 0);

        bool able = true;
        int last = 0;
        rep(i, n)
        {
            cin >> q;
            if (q < i + 1 || q > n || q < last)
                able = false;

            if (counter[q] == 0 && q > last)
            {
                p[i] = q;
                counter[q] = 1;
            }
        }

        if (!able)
        {
            cout << -1 << '\n';
            continue;
        }

        int i = 0;
        repx(j, 1, n)
        {
            while (i < n && p[i] != -1)
                i++;
            if (counter[j] == 0)
                p[i++] = j;
        }

        if (!able)
        {
            cout << -1 << '\n';
            continue;
        }

        rep(i, n) cout << p[i] << ' ';
        cout << '\n';
    }
}