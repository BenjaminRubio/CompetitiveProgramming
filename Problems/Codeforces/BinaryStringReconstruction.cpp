#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, x;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s >> x;
        int N = s.size();

        vector<int> w(N, 0); 
        bool flag = 1;
        rep(i, N)
        {
            if (s[i] == '1')
            {
                if (i >= x && (i < 2 * x || s[i - 2 * x] == '1')) w[i - x] = 1;
                else if (i < N - x && (i >= N - 2 * x || s[i + 2 * x] == '1')) w[i + x] = 1;
                else flag = 0;
            }
            else
            {
                if (i >= x && w[i - x] == 1) flag = 0;
                if (i < N - x && w[i + x] == 1) flag = 0;
            }
            if (!flag) break;
        }

        if (!flag) cout << -1 << '\n';
        else { rep(i, N) cout << w[i]; cout << '\n'; }
    }
}