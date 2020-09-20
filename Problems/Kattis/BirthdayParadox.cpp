#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, C;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(20);

    cin >> N;

    ld ans = 0, p = 1./365.;

    map<int, int> c;
    int D = 365, S = 0;
    rep(i, N)
    {
        cin >> C; S += C, c[C]++;

        ans -= lgamma(C + 1) / log(10);
    }
    ans += lgamma(S + 1) / log(10);
    ans += (ld)S * log10(p);
    ans += lgamma(N + 1) / log(10);

    for (auto &e : c) ans -= lgamma(e.second + 1) / log(10);
    ans += lgamma(365 + 1) / log(10);
    ans -= lgamma(N + 1) / log(10);
    ans -= lgamma(365 - N + 1) / log(10);

    cout << ans << '\n';
}