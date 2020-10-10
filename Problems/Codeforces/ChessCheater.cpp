#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K; char ch;
vector<bool> S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        S.resize(N);
        rep(i, N) { cin >> ch; S[i] = (ch == 'W'); }

        if (N == 1 && K == 0) { cout << S[0] << '\n'; continue; }
        else if (N == 1) { cout << 1 << '\n'; continue; }

        vector<int> O;

        int ans = 0;
        int l = -1, acc = 0, f = 2, L = 0;
        rep(i, N)
        {
            if (S[i] == 0) L++;
            if (S[i] != l)
            {
                if (l == 0 && f <= 0) O.emplace_back(acc);
                if (l == 1) ans += 2 * acc - 1;
                f--, acc = 0;
            }
            acc++, l = S[i];
        }
        if (l == 1) ans += 2 * acc - 1;

        sort(O.begin(), O.end());

        for (int o : O) if (K >= o) K -= o, ans += 2 * o + 1, L -= o;

        if (ans == 0 && K) cout << min(K, L) * 2 - 1 << '\n';
        else cout << ans + min(K, L) * 2 << '\n';
    }
}