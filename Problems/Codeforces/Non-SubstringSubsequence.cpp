#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, Q, l, r;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> Q >> S;

        while (Q--)
        {
            cin >> l >> r; l--, r--;

            bool b1 = 0, b2 = 0;
            for (int i = 0; i < l; i++) if (S[i] == S[l]) b1 = 1;
            for (int i = r + 1; i < N; i++) if (S[i] == S[r]) b2 = 1;
            if (b1 || b2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}