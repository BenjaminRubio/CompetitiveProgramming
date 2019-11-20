#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef vector<int> vi;
typedef long long ll;

int T, a, b;

int main()
{
    cin >> T;

    rep(t, T)
    {
        cin >> a >> b;

        if (a > b)
            swap(a, b);
        if (a == b)
        {
            cout << 0 << '\n';
            continue;
        }

        int c = 0;
        c += (b - a) / 5;

        if ((b - a) % 5 == 1)
            c += 1;
        if ((b - a) % 5 == 2)
            c += 1;
        if ((b - a) % 5 == 3)
            c += 2;
        if ((b - a) % 5 == 4)
            c += 2;

        cout << c << '\n';
    }
}