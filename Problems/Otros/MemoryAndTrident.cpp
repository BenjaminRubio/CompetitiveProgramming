#include <bits/stdc++.h>
using namespace std;

string s;

map<char, int> m = {{'L', 0}, {'R', 0}, {'U', 0}, {'D', 0}};

int main()
{
    cin >> s;

    if (s.size() % 2)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (char c : s) m[c]++;

    int ans = 0;

    ans += abs(m['L'] - m['R']) / 2;
    ans += abs(m['U'] - m['D']) / 2;
    if ((m['L'] + m['R']) % 2)
        ans++;

    cout << ans << '\n';
}