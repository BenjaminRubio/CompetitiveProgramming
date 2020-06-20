#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a;
queue<int> E, O;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        rep(i, 2 * N)
        {
            cin >> a;
            if (a % 2) O.push(i + 1);
            else E.push(i + 1);
        }

        if ((int)O.size() % 2 == 1) { O.pop(); E.pop(); }
        else if ((int)E.size() > 0) { E.pop(); E.pop(); }
        else { O.pop(); O.pop(); }

        while (!E.empty()) { cout << E.front() << ' '; E.pop(); cout << E.front() << '\n'; E.pop(); }
        while (!O.empty()) { cout << O.front() << ' '; O.pop(); cout << O.front() << '\n'; O.pop(); }
    }
}