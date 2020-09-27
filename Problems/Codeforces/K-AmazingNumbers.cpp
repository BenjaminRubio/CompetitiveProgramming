#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A, D, L;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        D.assign(N + 1, INT_MAX); L.assign(N + 1, 0);
        rep(i, N)
        {
            if (D[A[i]] == INT_MAX) D[A[i]] = i + 1 - L[A[i]];
            else D[A[i]] = max(D[A[i]], i + 1 - L[A[i]]);
            L[A[i]] = i + 1;
        }
        rep(i, N + 1) if (D[i] != INT_MAX) D[i] = max(D[i], N + 1 - L[i]);

        vector<pair<int, int>> V;
        rep(i, N + 1) if (D[i] != INT_MAX) V.emplace_back(D[i], i);

        sort(V.begin(), V.end());

        vector<int> ans(N + 1, INT_MAX); int i = 1, l = INT_MAX;
        for (auto &e : V)
        {
            while (i <= N && e.first > i) ans[i++] = l;
            l = min(e.second, l);
        }
        while (i <= N) ans[i++] = l;

        rep(i, N) cout << (ans[i + 1] != INT_MAX ? ans[i + 1] : -1) << ' ';
        cout << '\n';
    }
}