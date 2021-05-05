#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        cout << min({a, b, (a + b) / 3}) << '\n';
    }
}