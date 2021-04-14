#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N; double L;
vector<int> a;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(12);

    cin >> N >> L;

    a.resize(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());

    double l = 0, r = 1e9;
    rep(_, 1000)
    {
        double m = (l + r) * 0.5;

        bool check = true;
        double t = 0;
        rep(i, N)
        {
            if (t < a[i] - m) check = false;
            t = a[i] + m;
        }
        if (t < L) check = false;

        if (check) r = m;
        else l = m;
    }

    cout << (l + r) * 0.5 << '\n';
}