#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> c;

int main()
{
    cin >> n;

    c.resize(n);
    rep(i, n) cin >> c[i];

    sort(c.begin(), c.end(), greater<>());

    int H = -1;
    rep(i, n) H = max(H, min(c[i], i + 1));

    cout << H << '\n';
}