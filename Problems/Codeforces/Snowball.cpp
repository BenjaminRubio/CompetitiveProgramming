#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int w, h, u, d, u_, d_;

int main()
{
    cin >> w >> h >> u >> d >> u_ >> d_;

    if (d < d_)
    {
        swap(d, d_);
        swap(u, u_);
    }

    while (h > d) w += h, h--;
    w += h; h--;
    w = max(0, w - u);
    while (h > d_) w += h, h--;
    w += h; h--;
    w = max(0, w - u_);
    while (h > 0) w += h, h--;

    cout << w << '\n';
}