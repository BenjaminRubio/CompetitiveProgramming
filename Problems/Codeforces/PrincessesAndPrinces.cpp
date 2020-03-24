#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, k, p;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;

        vector<int> m(n, -1);
        vector<int> alone;
        rep(i, n)
        {
            cin >> k;
            bool done = false;
            rep(j, k)
            {
                cin >> p;
                if (!done and m[p - 1] == -1) m[p - 1] = i, done = true;
            }

            if (!done) alone.push_back(i);
        }

        bool improve = false;
        if (alone.size()) rep(i, n) if (m[i] == -1)
        {
            cout << "IMPROVE\n";
            cout << alone[0] + 1 << ' ' << i + 1 << '\n';
            improve = true;
            if (m[p - 1] > i) m[p - 1];
            break;
        }

        if (!improve) cout << "OPTIMAL\n";
    }
}