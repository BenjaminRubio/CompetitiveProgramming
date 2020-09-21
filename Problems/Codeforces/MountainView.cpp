#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, i, j; ld W, l, r, t, m1, m2, a1, a2;;
vector<ld> X, Y, P, S;

ld accR(int i, ld w) { return Y[i] * w + P[i] * w * w * 0.5; }
ld accL(int i, ld w) { return Y[i] * w + -P[i - 1] * w * w * 0.5; }

int main()
{
    cout.setf(ios::fixed); cout.precision(9);

    cin >> N >> W;

    X.resize(N); Y.resize(N); P.assign(N, 0);
    rep(i, N)
    {
        cin >> X[i] >> Y[i];
        if (i) P[i - 1] = (Y[i] - Y[i - 1]) / (X[i] - X[i - 1]);
    }

    S.assign(N, 0);
    repx(i, 1, N) S[i] = S[i - 1] + accR(i - 1, X[i] - X[i - 1]);

    if (X[N - 1] - X[0] <= W) { cout << S[N - 1] / W << '\n'; return 0; }

    ld ans = 0;
    i = 0, j = 0;
    while (i < N - 1 && j < N - 1)
    {
        while (j < N - 1 && X[j + 1] - X[i] < W) j++;
        if (j == N - 1) break;

        l = X[i], r = min(X[i + 1], X[j + 1] - W);
        rep(_, 1000)
        {
            t = (r - l) / 3.;
            m1 = l + t, m2 = r - t;

            a1 = S[j] - S[i] + accR(j, m1 + W - X[j]) - accR(i, m1 - X[i]);
            a2 = S[j] - S[i] + accR(j, m2 + W - X[j]) - accR(i, m2 - X[i]);

            if (a1 >= a2) r = m2;
            if (a2 >= a1) l = m1;
        }
        ans = max(ans, (a1 + a2) * 0.5);

        if (i)
        {
            l = max(X[j] - W, X[i - 1]), r = X[i];
            rep(_, 1000)
            {
                t = (r - l) / 3.;
                m1 = l + t, m2 = r - t;

                a1 = S[j] - S[i] + accR(j, m1 + W - X[j]) + accL(i, X[i] - m1);
                a2 = S[j] - S[i] + accR(j, m2 + W - X[j]) + accL(i, X[i] - m2);

                if (a1 >= a2) r = m2;
                if (a2 >= a1) l = m1;
            }
            ans = max(ans, (a1 + a2) * 0.5);
        }
        i++;
    }

    i = N - 1, j = N - 1;
    while (i > 0 && j > 0)
    {
        while (j > 0 && X[i] - X[j - 1] < W) j--;
        if (j == 0) break;

        r = X[i], l = max(X[i - 1], X[j - 1] + W);
        rep(_, 1000)
        {
            t = (r - l) / 3.;
            m1 = l + t, m2 = r - t;

            a1 = S[i] - S[j] + accL(j, X[j] - (m1 - W)) - accL(i, X[i] - m1);
            a2 = S[i] - S[j] + accL(j, X[j] - (m2 - W)) - accL(i, X[i] - m2);

            if (a1 >= a2) r = m2;
            if (a2 >= a1) l = m1;
        }
        ans = max(ans, (a1 + a2) * 0.5), i--;
    }

    cout << ans / W << '\n';
}