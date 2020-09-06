#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, p;
stack<int> s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        rep(_, N) { cin >> p; s.push(p); }
        while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
        cout << '\n';
    }
}