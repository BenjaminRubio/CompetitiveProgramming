#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        int aux = N - 2 * (3 + 5 + 7);
        if (aux > 0 && aux != 6 && aux != 10 && aux != 14)
        {
            cout << "YES\n";
            cout << "6 10 14" << ' ' << aux << '\n';
        }
        else if (aux > 1)
        {
            cout << "YES\n";
            cout << "6 10 15" << ' ' << aux - 1 << '\n';
        }
        else cout << "NO\n";
    }
}