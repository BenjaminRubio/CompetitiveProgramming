#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, L;
vector<int> A, B;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> T;
    while (T--)
    {
        cin >> N >> L;

        A.resize(N + 2);
        rep(i, N) cin >> A[i + 1];
        A[0] = 0, A[N + 1] = L;
        N += 2;

        B.resize(N);
        rep(i, N) B[i] = L - A[N - i - 1];

        double l = 0, r = 1e9;
        rep(_, 1000)
        {
            double m = (l + r) * .5;

            double t1 = 0, p1 = 0, v1 = 1, i1 = 1;
            while (i1 < N)
            {
                double d = A[i1] - A[i1 - 1];
                if (t1 + d / v1 <= m)
                {
                    t1 += d / v1;
                    v1 += 1;
                    p1 = A[i1++];
                }
                else { p1 += (m - t1) * v1; break; }
            }

            double t2 = 0, p2 = 0, v2 = 1, i2 = 1;
            while (i2 < N)
            {
                double d = B[i2] - B[i2 - 1];
                if (t2 + d / v2 <= m)
                {
                    t2 += d / v2;
                    v2 += 1;
                    p2 = B[i2++];
                }
                else { p2 += (m - t2) * v2; break; }
            }

            if (p1 + p2 > L) r = m;
            else l = m;
        }

        cout << l << '\n';
    }
}