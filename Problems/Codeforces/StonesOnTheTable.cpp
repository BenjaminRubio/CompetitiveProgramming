#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
string s;

int main()
{
    cin >> N >> s;

    int ans = 0;

    char l = '.';
    for (char c : s)
    {
        if (c == l) ans++;
        l = c;
    }

    cout << ans << '\n';
}