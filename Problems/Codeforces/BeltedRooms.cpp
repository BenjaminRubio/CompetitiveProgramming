#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N; char ch;
vector<int> B;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        bool l = 0, r = 0;
        B.assign(N, 0);
        rep(i, N)
        {
            cin >> ch;
            if (ch == '<') B[i] = -1, l = 1;
            if (ch == '>') B[i] = 1, r = 1;
        }

        int ans = 0;
        rep(i, N) ans += (!B[i] || !B[(i - 1 + N) % N] || (B[i] == B[(i - 1 + N) % N] && !(l && r)));

        cout << ans << '\n';
    }
}