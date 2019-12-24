#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int n, k;
char c;
string s;
set<char> keys;

int main()
{
    cin >> n >> k;
    cin >> s;
    
    rep(i, k)
    {
        cin >> c;
        keys.insert(c);
    }

    ll ans = 0;
    ll counter = 0;

    for (char ch : s)
    {
        if (keys.count(ch))
            counter++;
        else
        {
            ans += (counter * (counter + 1)) / 2;
            counter = 0;
        }
    }
    ans += (counter * (counter + 1)) / 2;

    cout << ans << '\n';
}