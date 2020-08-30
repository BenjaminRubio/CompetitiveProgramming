#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> C;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        C.assign(28, 0);
        rep(_, N)
        {
            cin >> s;
            for (char c : s) C[c - 'a']++;
        }

        rep(i, 28) if (C[i] % N) { cout << "NO\n"; goto next; }
        cout << "YES\n";

        next:
        continue;
    }
}