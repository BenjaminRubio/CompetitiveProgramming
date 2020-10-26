#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N;
vector<int> A, B;

int main()
{
    A.resize(6);
    rep(i, 6) cin >> A[i];

    cin >> N;

    B.resize(N);
    rep(i, N) cin >> B[i];

    vector<pair<int, int>> V;
    rep(i, N) rep(k, 6) V.emplace_back(B[i] - A[k], i);

    sort(V.begin(), V.end());

    int ans = 2e9, o = 0;
    vector<int> C(N, 0);
    queue<pair<int, int>> Q;
    for (auto &e : V)
    {
        C[e.ss]++; o += (C[e.ss] == 1); Q.push(e);
        while (C[Q.front().ss] > 1)
        {
            pair<int, int> aux = Q.front(); Q.pop(); C[aux.ss]--;
            if (o == N) ans = min(ans, e.ff - Q.front().ff);
        }
        if (o == N) ans = min(ans, e.ff - Q.front().ff);
    }

    cout << ans << '\n';
}