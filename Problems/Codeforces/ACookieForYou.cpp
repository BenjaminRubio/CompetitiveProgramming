#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, v, c, n, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> v >> c >> n >> m;

        if (v > c) swap(v, c);

        if (v < m) { cout << "No\n"; continue; }
        v -= m;

        if (v + c >= n) cout << "Yes\n";
        else cout << "No\n";
    }
}