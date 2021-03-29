#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, A;

int main()
{
    cin >> N;

    int ans = 0;

    int l = -1, c = 0;
    rep(_, N)
    {
        cin >> A;
        if ((A & 1) == l) c++;
        else
        {
            if (c & 1) ans++, c = 1;
            else if (ans) c = 2, ans--;
            else c = 1;
            l = (A & 1);
        }
    }
    if (c & 1) ans++;

    cout << ans << '\n';
}