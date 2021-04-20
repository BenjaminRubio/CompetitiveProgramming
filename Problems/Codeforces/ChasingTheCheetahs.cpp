#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> T, V;

double f(double t)
{
    double m = DBL_MAX, M = DBL_MIN;
    rep(i, N)
    {
        double p = V[i] * (t - T[i]);
        m = min(m, p), M = max(M, p);
    }
    return M - m;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(3);

    while (cin >> N && N)
    {
        T.resize(N), V.resize(N);
        rep(i, N) cin >> T[i] >> V[i];

        double l = *max_element(T.begin(), T.end()), r = 1e9;
        rep(_, 70)
        {
            double t = (r - l) / 3, m1 = l + t, m2 = r - t;
            double f1 = f(m1), f2 = f(m2);

            if (f1 <= f2) r = m2;
            if (f1 >= f2) l = m1;
        }

        cout << f((l + r) / 2) << '\n';
    }
}