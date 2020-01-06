#include <bits/stdc++.h>
using namespace std;

int T, k;
char type;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> k;
        int ans = 0;
        int aux = -1;
        while (k--)
        {
            cin >> type;
            if (type == 'A')
            {
                ans = max(ans, aux);
                aux = 0;
            }
            else if (type == 'P' && aux != -1)
                aux++;
        }
        ans = max(ans, aux);

        cout << ans << '\n';
    }
}