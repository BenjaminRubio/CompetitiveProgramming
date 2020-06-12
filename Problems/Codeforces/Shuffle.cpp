#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, x, m;
vector<int> l, r;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> x >> m; x--;

        l.resize(m); r.resize(m);
        rep(i, m) { cin >> l[i] >> r[i]; l[i]--; r[i]--; }

        int l_ = x, r_ = x;
        rep(i, m)
        {
            if (l[i] < l_ && r[i] >= l_) l_ = l[i], r_ = max(r_, r[i]);
            if (r[i] > r_ && l[i] <= r_) l_ = min(l_, l[i]), r_ = r[i];
        }

        cout << r_ - l_ + 1 << '\n';
    }
}