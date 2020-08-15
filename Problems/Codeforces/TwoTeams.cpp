#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K, j, k;
priority_queue<pair<int, int>> Q;
vector<int> A, L, R, V;

int main()
{
    cin >> N >> K;

    A.resize(N);
    rep(i, N) { cin >> A[i]; Q.emplace(A[i], i); }

    L.assign(N, -1); R.assign(N, -1);
    rep(i, N - 1) L[i + 1] = i, R[i] = i + 1;

    V.assign(N, 0); int t = 1;
    while (!Q.empty())
    {
        int i = Q.top().second; Q.pop();

        if (V[i]) continue;

        V[i] = t;
        
        j = i;
        rep(_, K) if (R[j] != -1) j = R[j], V[j] = t;

        k = i;
        rep(_, K) if (L[k] != -1) k = L[k], V[k] = t;

        if (R[j] != -1) L[R[j]] = L[k];
        if (L[k] != -1) R[L[k]] = R[j];

        t = t % 2 + 1; // 1 to 2 and 2 to 1
    }

    rep(i, N) cout << V[i];
    cout << '\n';
}