#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<double> A, S;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N;

    double ans = 0; A.resize(N);
    rep(i, N) cin >> A[i];

    S.assign(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + A[i];

    rep(i, N + 1) if (i) 
        ans = max({ans, S[i] / (double)i, (S[N] - S[N - i]) / (double)i});

    cout << ans << '\n';
}