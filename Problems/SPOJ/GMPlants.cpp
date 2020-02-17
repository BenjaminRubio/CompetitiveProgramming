#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;


struct SUM
{
    static ll const neutro = 0;
    static ll op(ll x, ll y) { return x + y; }
    static ll lazy_op(int i, int j, ll v) { return (j - i + 1) - v; }
};

template <class t>
class ST
{
    vector<ll> arr, st;
    vector<bool> lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j)
        {
            st[u] = arr[i];
            return;
        }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m);
        build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j)
    {
        st[u] = t::lazy_op(i, j, st[u]);
        if (i != j)
        {
            lazy[u * 2 + 1] = !lazy[u * 2 + 1];
            lazy[u * 2 + 2] = !lazy[u * 2 + 2];
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i)
            return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u])
            propagate(u, i, j);
        if (a <= i and j <= b)
            return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j);
        if (a <= i and j <= b) propagate(u, i, j);
        else if (j < a or b < i)
            return;
        else
        {
            update(a, b, l, i, m);
            update(a, b, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

  public:
    ST(vector<ll> &v)
    {
        arr = v;
        n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    ll query(int a, int b)
    {
        return query(a, b, 0, 0, n - 1);
    }

    void update(int a, int b)
    {
        update(a, b, 0, 0, n - 1);
    }
};

int T, Nx, Ny, Nz, Q, t, i, j, x, x_, y, y_, z, z_;
vector<ll> X, Y, Z;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> Nx >> Ny >> Nz >> Q;
        X.assign(Nx, 0); Y.assign(Ny, 0); Z.assign(Nz, 0);
        ST<SUM> stx(X), sty(Y), stz(Z);

        rep(q, Q)
        {
            cin >> t;
            if (t == 0)
            {
                cin >> i >> j;
                stx.update(i, j);
            }
            if (t == 1)
            {
                cin >> i >> j;
                sty.update(i, j);
            }
            if (t == 2)
            {
                cin >> i >> j;
                stz.update(i, j);
            }
            if (t == 3)
            {
                cin >> x >> y >> z >> x_ >> y_ >> z_;
                ll qx = stx.query(x, x_);
                ll qy = sty.query(y, y_);
                ll qz = stz.query(z, z_);
                ll dx = (x_ - x + 1), dy = (y_ - y + 1), dz = (z_ - z + 1);
                ll ans = 0;
                ans += (dx - qx) * (dy - qy) * qz;
                ans += (dy - qy) * (dz - qz) * qx;
                ans += (dz - qz) * (dx - qx) * qy;
                ans += qx * qy * qz;
                cout << ans << '\n'; 
            }
        }
    }
}