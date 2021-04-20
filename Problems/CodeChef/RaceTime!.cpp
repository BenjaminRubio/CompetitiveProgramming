#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K;
vector<double> S, D;

double f(double t)
{
    double m = DBL_MAX, M = DBL_MIN;
    rep(i, N)
    {
        double p = D[i] + t * S[i];
        m = min(m, p), M = max(M, p);
    }
    return M - m;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(6);

    cin >> N >> K;

    S.resize(N), D.resize(N);
    rep(i, N) cin >> S[i] >> D[i];

    double l = 0, r = K;
    rep(_, 1000)
    {
        double t = (r - l) / 3, m1 = l + t, m2 = r - t;
        double f1 = f(m1), f2 = f(m2);

        if (f1 <= f2) r = m2;
        if (f1 >= f2) l = m1;
    }

    cout << f((l + r) / 2) << '\n';
}