#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
ll a, b, c;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;

        if (b < c) swap(b, c);
        if (a < b) swap(a, b);
        if (b < c) swap(b, c);

        if (a > b + c) cout << a - b + c + 1 << '\n';
        else cout << 1 << '\n';
    }
}