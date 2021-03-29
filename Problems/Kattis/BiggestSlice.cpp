#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0L);

int M, N;
double R, a, m, s;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> M;
    while (M--)
    {
        cin >> R >> N >> a >> m >> s;

        double A = a / 360. + (m * 60. + s) / (360. * 3600.), c = 0;

        set<double> S = {0, 1}; N --;
        while (N--)
        {
            c += A;
            if (c > 1) c -= 1.;
            S.insert(c);
        }

        double l = 0, ans = 0;
        for (double d : S)
        {
            if (d - l > ans) ans = d - l;
            l = d;
        }

        cout << ans * (R * R) * PI << '\n';
    }
}