#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        if (N <= K) cout << K - N << '\n';
        else if ((N & 1) + (K & 1) == 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}