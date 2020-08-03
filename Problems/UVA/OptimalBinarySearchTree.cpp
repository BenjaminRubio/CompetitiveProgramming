#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N;
vector<int> F, A;
vector<vector<int>> DP, OPT;

int main()
{
    while (cin >> N)
    {
        F.assign(N + 1, 0);
        rep(i, N) cin >> F[i];

        A.assign(N + 1, 0);
        rep(i, N) A[i + 1] = F[i] + A[i];

        DP.assign(N + 1, vector<int>(N + 1, 0));
        OPT.assign(N + 1, vector<int>(N + 1));

        rep(i, N + 1) DP[i][i] = F[i], OPT[i][i] = i;

        repx(d, 1, N) rep(l, N - d)
        {
            int r = l + d, l_ = OPT[l][r - 1], r_ = OPT[l + 1][r];
            DP[l][r] = 1e9;
            repx(i, l_, r_ + 1)
            {
                int aux = (i ? DP[l][i - 1] : 0) + (i < N ? DP[i + 1][r] : 0) + A[r + 1] - A[l];
                if (aux < DP[l][r]) DP[l][r] = aux, OPT[l][r] = i;
            }
        }

        cout << DP[0][N - 1] - A[N] << '\n';
    }
}