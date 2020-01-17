#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, d;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> n >> d;

        bool done = false;

        rep(i, int(sqrt(d)))
        {
            int ans = i + (int)ceil((double)d / (double)(i + 1));
            if (ans <= n)
            {
                done = true;
                break;
            }
        }

        if (done)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}