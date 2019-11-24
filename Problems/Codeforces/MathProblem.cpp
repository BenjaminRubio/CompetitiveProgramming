#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, l, r, l_, r_, n;

int main()
{
    cin >> T;
    rep(t, T)
    {
        l_= -1;
        r_ = INT_MAX;
        cin >> n;
        rep(i, n)
        {
            cin >> l >> r;
            l_ = max(l_, l);
            r_ = min(r_, r);
        }

        cout << max(l_ - r_, 0) << '\n';
    }
}