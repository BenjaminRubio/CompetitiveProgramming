#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef vector<int>::iterator iter;

int T, n, x;
vector<int> p;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        p.resize(n);
        rep(i, n)
        {
            cin >> x;
            p[x - 1] = i;
        }

        int m = 1e9;
        int M = -1;
        rep(i, n)
        {
            m = min(m, p[i]);
            M = max(M, p[i]);

            if (M - m == i)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}