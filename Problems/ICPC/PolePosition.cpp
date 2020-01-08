#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long N, C, P;
vector<long long> p;

int main()
{
    while (cin >> N)
    {
        if (N == 0)
            break;

        bool done = false;

        p.assign(N, -1);
        rep(i, N)
        {
            cin >> C >> P;
            C--;

            if (i + P >= 0 && i + P < N && p[i + P] == -1)
                p[i + P] = C;
            else
                done = true;
        }

        if (!done)
        {
            rep(i, N - 1) cout << p[i] + 1 << ' ';
            cout << p[N - 1] + 1 << '\n';
        }
        else
            cout << -1 << '\n';
    }
}