#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string s;

int main()
{
    cin >> s;
    int n = s.size();

    int f = 0, p;
    rep(i, n)
    {
        if (s[n - i - 1] == ')') f++;
        if (s[n - i - 1] == '(') f--;
        if (s[n - i - 1] == '#')
        {
            p = n - i - 1;
            break;
        }
    }

    bool pos = true;
    int c = 0, aux;
    rep(i, n)
    {
        if (s[i] == '(') c++;
        if (s[i] == ')') c--;
        if (s[i] == '#' and i < p) c--;
        if (i == p) { aux = c - f; c -= (c - f); }
        if (c < 0) pos = false;
    }

    if (!pos or c != 0 or aux <= 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    rep(i, n)
    {
        if (s[i] == '#' and i < p) cout << 1 << '\n';
        if (i == p) cout << aux << '\n';
    }
}