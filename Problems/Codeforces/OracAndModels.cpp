#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 1; i < (int)n + 1; i++)
#define rep_(i, n) for (int i = (int)n; i > 0; i--)

int T, n;
vector<int> s, c;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        s.resize(n); c.assign(n, 0);
        rep(i, n) cin >> s[i - 1];

        int M = -1;
        rep_(i, n)
        {
            rep(j, (n / i) + 2) if (j > 1)
            {
                if (i * j <= n && s[(i * j) - 1] > s[i - 1])
                {
                    c[i - 1] = max(c[i - 1], c[(i * j) - 1] + 1);
                }
            }
            M = max(M, c[i - 1]);
        }

        cout << M + 1 << '\n';
    }
}