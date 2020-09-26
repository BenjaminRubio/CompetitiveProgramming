#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string s;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> s;
        string A;

        int l = 0;
        for (char c : s)
        {
            int d = (c - '0') - l;
            if (d > 0) rep(_, d) A += '(';
            else rep(_, -d) A += ')';
            A += c;
            l = (c - '0');
        }
        rep(_, l) A += ')';

        cout << "Case #" << t + 1 << ": " << A << '\n';
    }
}