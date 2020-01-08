#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int S;
string B;

int main()
{
    cin >> B >> S;
    int n = B.size();

    long long ans = 0;
    int last = -1;
    rep(i, n + S)
    {
        if (last != -1 && last <= i - S)
            last = -1;
        if (B[i % n] == 'E')
        {
            if (i >= S)
                ans += S;
            last = i;
        }
        else if (last != -1 && i >= S)
            ans += S - (i - last);
    }

    cout << ans << '\n';
}