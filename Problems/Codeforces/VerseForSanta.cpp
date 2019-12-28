#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long T, n, s;
vector<long long> a, partial;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> s;

        a.resize(n);
        rep(i, n) cin >> a[i];

        long long aux = 0;
        partial.assign(n + 1, 0LL);
        rep(i, n + 1)
        {
            partial[i] = aux;
            aux += a[i];
        }

        aux = 0;
        long long ans = 0;
        rep(i, n + 1) if (partial[i] <= s) aux = i;

        if (aux == n)
        {
            cout << 0 << '\n';
            continue;
        }
        aux = 0;
        rep(i, n)
        {
            long long l = 0;
            long long r = n + 1;

            while (l < r)
            {
                long long m = (l + r) / 2LL;
                long long q = partial[m];
                if (m >= i + 1)
                    q -= a[i];
                if (q > s)
                    r = m;
                else
                    l = m + 1;
            }
            l--;

            if (l - 1 > aux)
            {
                aux = l - 1;
                ans = i + 1;
            }
        }

        if (ans == 0)
            cout << 1 << '\n';
        else
            cout << ans << '\n';
    }
}