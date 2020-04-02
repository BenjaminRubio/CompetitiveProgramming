#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
double T;
vector<double> D, V;

int main()
{
    cout.setf(ios::fixed); cout.precision(10);

    cin >> N >> T;

    double l = DBL_MAX, r = 10000000;
    D.resize(N); V.resize(N);
    rep(i, N) cin >> D[i] >> V[i];

    rep(i, N) l = min(l, V[i]);
    l = -l;

    rep(_, 1000)
    {
        double m = (l + r) * 0.5;

        double t = 0;
        rep(i, N) t += D[i] / (V[i] + m);

        if (t < T) r = m;
        else l = m;
    }

    cout << (l + r) * 0.5 << '\n';
}