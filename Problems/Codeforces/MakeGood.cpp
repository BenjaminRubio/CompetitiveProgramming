#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
long long a;
vector<long long> moves;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        long long s = 0LL;
        long long x = 0LL;
        rep(i, n)
        {
            cin >> a;
            s += a;
            x ^= a;
        }
        x <<= 1LL;

        long long t1 = 0LL;
        long long t2 = 0LL;
        rep(i, 60)
        {
            long long b = 1LL << (long long)i;
            if ((b & s) && !(b & x))
            {
                t1 |= b;
                s += b;
                x ^= b << 1LL;
            }
            else if (!(b & s) && (b & x))
            {
                t2 |= (b >> 1LL);
                s += b;
            }
        }

        if (t1 && t2)
        {
            cout << 3 << '\n';
            cout << t1 << ' ' << t2 << ' ' << t2 << '\n';
        }
        else if (t1)
        {
            cout << 1 << '\n';
            cout << t1 << '\n';
        }
        else if (t2)
        {
            cout << 2 << '\n';
            cout << t2 << ' ' << t2 << '\n';
        }
        else
        {
            cout << 0 << '\n';
            cout << '\n';
        }
    }
}