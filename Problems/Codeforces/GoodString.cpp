#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s; int N = s.size();

        map<int, int> m;
        rep(i, N) m[s[i] - '0']++;

        int M = 0;
        rep(i, 10) M = max(M, m[i]);

        int ans = N - M;

        rep(i, 10) rep(j, 10)
        {
            int aux = 0; bool flag = 0;
            rep(k, N)
            {
                if (flag && int(s[k] - '0') == i) { aux++; flag = !flag; }
                else if (!flag && int(s[k] - '0') == j) { aux++; flag = !flag; }
            }
            if (aux & 1) aux--;
            ans = min(ans, N - aux);
        }

        cout << ans << '\n';
    }
}