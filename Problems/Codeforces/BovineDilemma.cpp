#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X[50];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        rep(i, N) cin >> X[i];

        set<int> s;
        rep(i, N) rep(j, N) if (i != j) s.insert(abs(X[i] - X[j]));

        cout << s.size() << '\n';
    }
}