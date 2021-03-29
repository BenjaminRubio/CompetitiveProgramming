#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N, C;
vector<int> L;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> N >> C;

        if (C < N - 1 || C > ((N * (N + 1)) / 2 - 1))
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        L.resize(N);
        rep(i, N) L[i] = i + 1;

        C -= N - 1;

        stack<pair<int, int>> S;
        rep(i, N - 1)
        {
            if (C >= N - i - 1) { S.emplace(i, N); C -= (N - i - 1); }
            else { S.emplace(i, i + C + 1); C = 0; }
        }

        int i, j;
        while (!S.empty())
        {
            tie(i, j) = S.top(); S.pop();
            vector<int> L_ = L;
            repx(k, i, j) L_[k] = L[j - 1 - (k - i)];
            L = L_;
        }

        rep(i, N) cout << L[i] << ' ';
        cout << '\n';
    }
}