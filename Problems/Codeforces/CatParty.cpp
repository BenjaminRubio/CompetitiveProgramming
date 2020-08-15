#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, u;
vector<int> C;
multiset<int> ms;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int ans = -1;
    C.assign(100010, 0);
    rep(i, N)
    {
        cin >> u;

        if (C[u]) ms.erase(ms.find(C[u]));
        ms.insert(++C[u]);

        auto f = ms.begin(), l = --ms.end();

        if (ms.size() == 1) ans = i + 1;

        if (*f == *l - 1 && *f == *(--l))
            ans = i + 1;
        
        l = --ms.end();
        if (*f == 1 && *l == *(++f))
            ans = i + 1;
    }

    cout << ans << '\n';
}