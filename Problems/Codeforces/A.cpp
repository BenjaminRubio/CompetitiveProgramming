#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int t, n;
string num;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> num;

        bool done = false;
        int primes = 0;
        int c;
        rep(i, n)
        {
            if (int(num[i]) % 2)
            {
                primes++;
                if (primes == 2)
                {
                    cout << num[c] << num[i] << '\n';
                    done = true;
                    break;
                }
                c = i;
            }
        }

        if (!done) cout << -1 << '\n';
    }
}