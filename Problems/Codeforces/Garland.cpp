#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, x;
vector<int> p, p_;

int main()
{
    cin >> n;

    p.resize(n);
    rep(i, n) cin >> p[i];

    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    int e = n / 2;
    int o = n - n / 2;
    int ceros = 0;
    rep(i, n)
    {
        if (p[i] % 2)
            o--;
        else if (p[i] != 0)
            e--;
        if (p[i] == 0)
            ceros++;
    }

    int e_ = 0;
    int o_ = 0;
    int aux = 0;
    int last = -1;
    rep(i, n)
    {
        if (p[i])
        {
            if (last == -1 || last == (p[i] % 2))
            {
                if (p[i] % 2 == 0)
                    e_ += aux;
                else
                    o_ += aux;
            }
            last = (p[i] % 2);
            aux = 0;
        }
        else
            aux++;
    }
    if (last != -1 && last % 2 == 0)
        e_ += aux;
    else if (last != -1)
        o_ += aux;

    int ans;
    ans = min(o_ - o, e_ - e) * 2 + (ceros - o_ - e_);

    cout << ans + 1 << '\n';
}