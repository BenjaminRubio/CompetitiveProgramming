#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int k;

int main()
{
    cin >> k;

    int l;
    rep(i, 30) if (k & (1 << i)) l = i;

    cout << "2 3\n";
    cout << (1 << (l + 2)) - 1 << ' ' << k << ' ' << 0 << '\n';
    cout << (1 << (l + 1)) << ' ' << (1 << (l + 2)) - 1 << ' ' << k << '\n';
}