#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M, D[510][510];
vector<vector<int>> A, B;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        char x;
        rep(i, N) rep(j, M)
        {
            cin >> x;
            D[i][j] = (x == '*');
        }

        int ans = 0;
        A.assign(N, vector<int>(M));
        B.assign(N, vector<int>(M));
        rep(i, N) rep(j, M) B[i][j] = D[i][j], ans += B[i][j];

        rep(k, N)
        {
            rep(i, N) rep(j, M)
            {
                A[i][j] = (D[i][j] && i < N - 1 && j && j < M - 1 && B[i + 1][j - 1] && B[i + 1][j] && B[i + 1][j + 1]);
                ans += A[i][j];
            }
            swap(A, B);
        }

        cout << ans << '\n';
    }
}