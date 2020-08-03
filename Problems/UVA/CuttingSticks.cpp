#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int L, N;
vector<int> C;
vector<vector<int>> DP, OPT;

int main()
{
    while (cin >> L && L)
    {
        cin >> N;
        
        C.resize(N + 2); C[0] = 0, C[N + 1] = L;
        rep(i, N) cin >> C[i + 1];
        N = N + 1;

        DP.assign(N + 1, vector<int>(N + 1, 1e9));
        OPT.assign(N + 1, vector<int>(N + 1));

        rep(i, N) DP[i][i + 1] = C[i + 1] - C[i], OPT[i][i + 1] = i;

        repx(d, 2, N + 1) rep(l, N + 1 - d)
        {
                int r = l + d, l_ = OPT[l][r - 1], r_ = OPT[l + 1][r];
                repx(i, l_, r_ + 1)
                {
                    int aux = DP[l][i] + DP[i][r] + C[r] - C[l];
                    if (aux < DP[l][r]) DP[l][r] = aux, OPT[l][r] = i;
                }
        }

        cout << "The minimum cutting is " << DP[0][N] - L << ".\n";
    }
}