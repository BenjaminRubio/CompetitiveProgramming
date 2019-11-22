#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

double w, d, a, k;
vector<double> p1, q1, p2, q2;

double eval_f1(double x)
{
    double x_ = 1;
    double p = 0;
    double q = 0;
    rep(i, k + 1)
    {
        p += p1[i] * x_;
        q += q1[i] * x_;
        x_ *= x;
    }
    return p / q;
}

double eval_f2(double x)
{
    double x_ = 1;
    double p = 0;
    double q = 0;
    rep(i, k + 1)
    {
        p += p2[i] * x_;
        q += q2[i] * x_;
        x_ *= x;
    }
    return p / q;
}

double integrate(double d_)
{
    double ans = 0;
    double delta = (double)w * 0.0001;
    rep(i, 10000)
    {
        double x = (double)i * delta + delta * 0.5;

        double f1 = -1.0 * eval_f1(x);
        double f2 = -1.0 * eval_f2(x);

        if (d_ <= f1)
            ans += 0;
        else if (d_ >= f2)
            ans += f2 - f1;
        else
            ans += d_ - f1;
    }
    return ans * delta;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(5);

    while (cin >> w >> d >> a >> k)
    {
        p1.resize(k + 1);
        q1.resize(k + 1);
        p2.resize(k + 1);
        q2.resize(k + 1);
        rep(i, k + 1) cin >> p1[i];
        rep(i, k + 1) cin >> q1[i];
        rep(i, k + 1) cin >> p2[i];
        rep(i, k + 1) cin >> q2[i];

        double i = 0;
        double j = d;
        rep(t, 100)
        {
            double m = (i + j) * 0.5;
            if (integrate(m) >= a)
                j = m;
            else
                i = m;
        }

        cout << i << '\n';
    }
}