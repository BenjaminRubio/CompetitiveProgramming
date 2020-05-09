#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 1) cout << 3 << '\n';
    else if (n == 2) cout << 4 << '\n';
    else cout << (n - 2) << '\n';
}