#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int T, x, y;
    
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> y;
    
        cout << x + y + abs(x - y) - bool(abs(x - y)) << '\n';
    }
}