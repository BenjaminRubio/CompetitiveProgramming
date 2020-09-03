#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, t, a, b;
vector<int> A, B, J;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    A.resize(N); B.resize(N); J.resize(N);
    rep(i, N) cin >> A[i];

    int S = sqrt(N + 0.) + 1;

    rep(i, S) for (int j = min(N, (i + 1) * S) - 1; j >= i * S; j--)
    {
        if (j + A[j] >= min(N, (i + 1) * S)) B[j] = j, J[j] = 1;
        else B[j] = B[j + A[j]], J[j] = J[j + A[j]] + 1;
    }

    while (M--)
    {
        if (cin >> t && !t)
        {
            cin >> a >> b; a--;
            A[a] = b;
            int i = a / S;
            for (int j = min(N, (i + 1) * S) - 1; j >= i * S; j--)
            {
                if (j + A[j] >= min(N, (i + 1) * S)) B[j] = j, J[j] = 1;
                else B[j] = B[j + A[j]], J[j] = J[j + A[j]] + 1;
            }
        }
        else
        {
            cin >> a; a--;

            int c = 0;
            while (1)
            {
                c += J[a], a = B[a];
                if (a + A[a] >= N) break;
                a += A[a];
            }
            cout << a + 1 << ' ' << c << '\n';
        }
    }
}