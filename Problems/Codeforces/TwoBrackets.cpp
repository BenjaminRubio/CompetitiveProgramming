#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int T;
string S;
    
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> S;
    
        int p1 = 0, p2 = 0, ans = 0;
        for (char c : S)
        {
            if (c == '(') p1++;
            if (c == '[') p2++;
            if (c == ')') ans += bool(p1), p1 = max(p1 - 1, 0);
            if (c == ']') ans += bool(p2), p2 = max(p2 - 1, 0);
        }
    
        cout << ans << '\n';
    }
}