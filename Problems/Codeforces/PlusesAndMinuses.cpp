#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;

        ll ans = 0, sum = 0, id = 0;
        for (char ch : s)
        {
            id++;
            if (ch == '-') sum--;
            else sum++;

            if (sum < 0) ans += id, sum++;
        }
        ans += (ll)s.size();

        cout << ans << '\n';
    }
}