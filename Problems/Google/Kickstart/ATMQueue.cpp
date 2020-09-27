#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X;
vector<int> A, C;

int main()
{
    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> N >> X;

        A.resize(N);
        rep(i, N) cin >> A[i];

        vector<pair<int, int>> S;
        rep(i, N) S.emplace_back((A[i] - 1) / X, i);
        
        sort(S.begin(), S.end());

        for (auto &e : S) cout << e.second + 1 << ' ';
        cout << '\n';
    }
}