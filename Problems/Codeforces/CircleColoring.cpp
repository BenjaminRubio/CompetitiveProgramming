#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A, B, C, V;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N), B.resize(N), C.resize(N);
        rep(i, N) cin >> A[i];
        rep(i, N) cin >> B[i];
        rep(i, N) cin >> C[i];

        V.assign(N, -1); V[0] = A[0];
        rep(i, N) if (i)
        {
            if (A[i] != V[i - 1] && A[i] != V[(i + 1) % N]) V[i] = A[i];
            if (B[i] != V[i - 1] && B[i] != V[(i + 1) % N]) V[i] = B[i];
            if (C[i] != V[i - 1] && C[i] != V[(i + 1) % N]) V[i] = C[i];
        }

        rep(i, N) cout << V[i] << ' ';
        cout << '\n';
    }
}