#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        set<int> S;
        bool done = 0;
        rep(i, N)
        {
            cin >> x;
            if (S.count(x)) done = 1;
            else S.insert(x);
        }
        if (done) cout << "YES\n";
        if (!done) cout << "NO\n";
    }
}