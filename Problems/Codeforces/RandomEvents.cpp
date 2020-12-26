#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M, x; double p;
vector<int> A;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        A.resize(N);
        rep(i, N) cin >> A[i];

        int l = N;
        while (l && A[l - 1] == l) l--;

        double ans = 0, n = 1;
        rep(_, M)
        {
            cin >> x >> p;
            if (x >= l) ans += n * p, n *= (1. - p);
        }

        if (l) cout << ans << '\n';
        else cout << 1. << '\n';
    }
}