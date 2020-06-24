#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> s;

        int c = 0;
        while (c < s.size() && s[c] == '0') c++;
        int o = 0;

        bool p = 0;
        repx(i, c, N) if (s[i] == '0') p = 1;

        while (N - o - 1 >= 0 && s[N - o - 1] == '1') o++;

        rep(i, c + p) cout << '0';
        rep(i, o) cout << '1';
        cout << '\n';
    }
}