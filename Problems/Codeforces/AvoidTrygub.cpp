#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
string a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> a;

        sort(a.begin(), a.end());

        cout << a << '\n';
    }
}