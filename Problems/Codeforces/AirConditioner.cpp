#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Customer
{
    int t, l, h;
    Customer(int t, int l, int h) : t(t), l(l), h(h) {}
    bool operator<(Customer &c)
    {
        return t < c.t;
    }
};

int q, n, m, t, l, h;
vector<Customer> cust;

int main()
{
    cin >> q;
    rep(_, q)
    {
        cust.clear();
        cin >> n >> m;

        rep(i, n)
        {
            cin >> t >> l >> h;
            cust.emplace_back(t, l, h);
        }

        sort(cust.begin(), cust.end());

        t = 0, l = m, h = m;
        bool pos = true;
        for (Customer c : cust)
        {
            int d = c.t - t;
            if (c.h < l - d) pos = false;
            if (c.l > h + d) pos = false;
            l = max(l - d, c.l);
            h = min(h + d, c.h);
            t = c.t;
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}