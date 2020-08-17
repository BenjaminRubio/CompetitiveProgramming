#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        set<int> s;
        rep(i, N) { cin >> A; s.insert(A); }

        if (s.size() == 1) cout << N << '\n';
        else cout << 1 << '\n';
    }
}