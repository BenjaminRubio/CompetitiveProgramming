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

        int c = 0, b = 0, ans = 0;
        for (char ch : S)
        {
            if (ch == 'A') c++;
            if (ch == 'B')
            {
                if (c) ans += 2, c--;
                else b++;
            }
        }
        ans += 2 * (b / 2);

        cout << (int)S.size() - ans << '\n';
    }
}