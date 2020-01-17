#include <bits/stdc++.h>
using namespace std;

long long T, A, B;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> A >> B;

        long long B_ = log10(B + 1);

        long long ans = B_ * A;

        cout << ans << '\n';
    }
}