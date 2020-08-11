#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        rep(i, N) cout << i + 1 << ' ';
        cout << '\n';
    }
}