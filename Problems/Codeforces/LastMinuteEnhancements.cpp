#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X[100000];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        rep(i, N) cin >> X[i];

        set<int> s; int l = 0;
        rep(i, N)
        {
            if (X[i] <= l) s.insert(X[i] + 1), l = max(l, X[i] + 1);
            else s.insert(X[i]), l = max(l, X[i]);
        }

        cout << s.size() << '\n';
    }
}