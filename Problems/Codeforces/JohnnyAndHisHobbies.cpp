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

        set<int> v;
        rep(i, N) { cin >> x; v.insert(x); }

        bool done = false;
        rep(i, 1024) if (i)
        {
            set<int> s;
            for (int x : v) s.insert(x ^ i);

            bool flag = false;
            for (int x : s) if (!v.count(x)) flag = true;

            if (!flag && s.size() == N)
            {
                cout << i << '\n';
                done = true;
                break;
            }
        }

        if (!done) cout << -1 << '\n';
    }
}