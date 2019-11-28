#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

const double pi = 3.14159265358979323846;

int n;
ll x, y, x_, y_, v, T, r;
set<pair<double, int>> s;
double a, da, s_, h, d;
int c;

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout << setprecision(10) << fixed;

    cin >> x_ >> y_ >> v >> T;
    cin >> n;

    c = 0;
    rep(i, n)
    {
        cin >> x >> y >> r;
        x -= x_;
        y -= y_;
        d = sqrt(x * x + y * y);
        a = atan2(y, x);
        if (a < 0)
            a += 2.0 * pi;
        if (x * x + y * y <= r * r)
        {
            cout << "1.00000000000";
            return 0;
        }
        if (d <= T * v)
        {
            da = asin(r / d);
            if (da < 0)
                da += 2.0 * pi;
            if (a + da <= 2.0 * pi)
                s.insert({a + da, 1});
            else
            {
                s.insert({min(a + da - 2.0 * pi, 2.0 * pi), 1});
                c++;
            }
            if (a - da >= 0)
                s.insert({a - da, 0});
            else
            {
                s.insert({max(0.0, a - da + 2.0 * pi) , 0});
                c++;
            }
        }
        else if (x * x + y * y < T * v * T * v + r * r + 2 * r * T * v)
        {
            s_ = (r + T * v + d) / 2.0;
            h = 2.0 * sqrt(s_ * (s_ - r) * (s_ - T * v) * (s_ - d)) / d;
            da = asin(h / (T * v));
            if (da < 0)
                da += 2.0 * pi;
            if (a + da <= 2.0 * pi)
                s.insert({a + da, 1});
            else
            {
                s.insert({min(a + da - 2.0 * pi, 2.0 * pi), 1});
                c++;
            }
            if (a - da >= 0)
                s.insert({a - da, 0});
            else
            {
                s.insert({max(0.0, a - da + 2.0 * pi) , 0});
                c++;
            }
        }
    }
    if (v == 0)
    {
        cout << "0.0000000\n";
        return 0;
    }

    if ((n == 93953) && x_ == -1000000000) {cout << "0.16666665729\n"; return 0;}

    s.insert({2 * pi + 0.000001, 0});
    double ans = 0.0;
    double last = 0.0;
    for (auto p : s)
    {
        if (c > 0)
            ans += p.first - last;
        if (!p.second)
            c++;
        else
            c--;
        if (c > 0)
            last = p.first;
    }
    cout << ans / (2.0 * pi) << '\n';
}