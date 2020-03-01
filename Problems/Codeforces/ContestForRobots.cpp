#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> r1, r2;

int main()
{
    cin >> n;

    r1.resize(n);
    rep(i, n) cin >> r1[i];
    r2.resize(n);
    rep(i, n) cin >> r2[i];

    int aux1 = 0, aux2 = 0;
    rep(i, n)
    {
        if (r1[i] and !r2[i]) aux1++;
        if (!r1[i] and r2[i]) aux2++;
    } aux2++;

    if (!aux1)
    {
        cout << -1 << '\n';
        return 0;
    }

    int d = aux2 / aux1;
    if (d * aux1 != aux2) cout << d + 1 << '\n';
    else cout << d << '\n';
}