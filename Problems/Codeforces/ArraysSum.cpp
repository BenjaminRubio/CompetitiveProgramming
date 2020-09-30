#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K, a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        set<int> s;
        rep(i, N) { cin >> a; s.insert(a); }

        if (K == 1) { (s.size() == 1 ? cout << 1 << '\n' : cout << -1 << '\n'); continue; }

        int S = s.size();

        if (S <= K) { cout << 1 << '\n'; continue; }
        S -= K;

        cout << 2 + ((S - 1) / (K - 1)) << '\n';
    }
}