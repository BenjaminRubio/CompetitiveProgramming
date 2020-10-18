#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;

        cout << (a ^ b) << '\n';
    }
}