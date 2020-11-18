#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> A, C, L;
vector<vector<int>> D;

int main()
{
    cin >> N;

    int mx = 0, id;
    A.resize(N); C.assign(100, 0);
    rep(i, N)
    {
        cin >> A[i]; A[i]--; C[A[i]]++;
        if (C[A[i]] > mx) mx = C[A[i]], id = A[i];
    }

    C.assign(100, 0);
    D.assign(N, vector<int>(100));
    rep(i, N)
    {
        C[A[i]]++;
        rep(j, 100) D[i][j] = C[j] - C[id];
    }

    int ans = 0;
    rep(j, 100) if (j != id)
    {
        L.assign(2 * N + 1, -1); L[N] = 0;
        rep(i, N)
        {
            if (L[N + D[i][j]] == -1) L[N + D[i][j]] = i + 1;
            else ans = max(ans, i - L[N + D[i][j]] + 1);
        }
    }

    cout << ans << '\n';
}