#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> S;

        int o = 0, c = 0;
        rep(i, K)
        {
            bool flag = true;
            char v = S[i];
            for (int j = i; j < N; j += K) if (S[j] != '?' && S[j] != v)
            {
                if (v == '?') v = S[j];
                else flag = false;
            }

            if (!flag) { cout << "NO\n"; goto next; }
            for (int j = i; j < N; j += K) S[j] = v;
        }

        rep(i, K)
        {
            if (S[i] == '1') o++;
            if (S[i] == '0') c++;
        }
        if (o > K / 2 || c > K / 2) cout << "NO\n";
        else cout << "YES\n";

        next:
        continue;
    }
}