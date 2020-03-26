#include <bits/stdc++.h>
using namespace std;

string sa, sb;

int main()
{
    cin >> sa >> sb;

    int base = 0;
    for (char c : sa) base = max(base, c - '0' + 1);
    for (char c : sb) base = max(base, c - '0' + 1);

    int a = stoi(sa), b = stoi(sb);

    int ans = 0, prev = 0;
    while (a + b + prev)
    {
        prev = (a % 10 + b % 10 + prev) / base;
        a /= 10; b /= 10;
        ans++;
    }

    cout << ans << '\n';
}