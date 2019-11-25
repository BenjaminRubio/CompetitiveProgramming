#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

const double PI = 3.14159265358979323846;

struct Point
{
    double x, y;
    double norm2()
    {
        return x * x + y * y;
    }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0)
            return a + 2.0 * PI;
        return a;
    }
};

int N;
double X, Y;
vector<Point> plant;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    cin >> N;

    plant.resize(N);
    rep(i, N)
    {
        cin >> X >> Y;
        plant[i] = {X, Y};
    }

    double rmin = 0;
    double rmax = 1e10;
    rep(k, 500)
    {
        double m = (rmin + rmax) * 0.5;

        set<pair<double, int>> events;
        int counter = 0;

        bool able = false;

        rep(i, N)
        {
            if (plant[i].norm2() >= 2 * m * m)
            {
                counter++;
                continue;
            }

            if (plant[i].norm2() < m * m)
                goto not_able;

            double a = plant[i].ang();
            double da = acos(m / sqrt(plant[i].norm2()));
            double a1 = a - da;
            double a2 = a + da;

            if (a1 < 0)
                a1 += 2.0 * PI;
            while (a1 >= 0.5 * PI)
                a1 -= 0.5 * PI;
            while (a2 >= 0.5 * PI)
                a2 -= 0.5 * PI;

            events.insert({a1, 0});
            events.insert({a2, 1});

            if (a2 < a1)
                counter++;
        }

        if (counter >= N)
            able = true;
        
        for (auto e : events)
        {
            if (e.second == 0)
                counter++;
            if (e.second == 1)
                counter--;
            if (counter >= N)
            {
                able = true;
                break;
            }
        }

    not_able:

        if (able)
            rmin = m;
        else
            rmax = m;
    }

    cout << (8.0 * rmin) << '\n';
}