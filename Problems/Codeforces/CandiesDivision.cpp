#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        if (n % k > k / 2)
            cout << n / k * k + k / 2 << '\n';
        else
            cout << n << '\n';
    }
}