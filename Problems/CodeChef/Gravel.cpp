#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct FenwickTree
{
    vector<ll> FT;
    FenwickTree(int N)
    {
        FT.resize(N + 1, 0);
    }

    ll query(int i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i))
            ans += FT[i];
        return ans;
    }

    void update(int i, ll v)
    {
        for (; i < FT.size(); i += i & (-i))
            FT[i] += v;
    }

    void update(int i, int j, ll v)
    {
        update(i, v);
        update(j + 1, -v);
    }
};

int n, m, c, i, j;
ll k;
char t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> c;

    FenwickTree ft(n);

    rep(_, m)
    {
        cin >> t;

        if (t == 'S')
        {
            cin >> i >> j >> k;
            ft.update(i, j, k);
        }

        if (t == 'Q')
        {
            cin >> i;
            cout << ft.query(i) + c << '\n';
        }
    }
}