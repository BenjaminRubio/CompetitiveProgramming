#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, x;
vector<int> ans;

int main()
{
    cin >> n;

    int aux = 0;
    rep(i, n)
    {
        cin >> x;
        cout << aux + x << ' ';
        aux = max(aux, aux + x);
    }
    cout << '\n';
}