#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll K;
string base = "codeforces";

int main()
{
    cin >> K;

    ll C = 1, R = 0, curr = 1;
    while (C < K)
    {
        C += C / curr;
        R++;
        if (R % 10 == 0) curr++;
    }

    rep(i, 10)
    {
        rep(_, curr + bool(R % 10)) cout << base[i];
        if (bool(R % 10)) R--;
    }
    cout << '\n';
}