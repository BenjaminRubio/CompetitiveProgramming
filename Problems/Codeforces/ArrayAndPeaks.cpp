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
        if (K > ((N / 2) - !(N & 1))) { cout << -1 << '\n'; continue; }

        int i = 1, j = N;
        while (K--)
        {
            cout << i << ' ' << j << ' ';
            i++, j--;
        }
        
        for (int x = i; x <= j; x++) cout << x << ' ';
        cout << '\n';
    }
}