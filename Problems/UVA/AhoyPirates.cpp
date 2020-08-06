#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

class STL
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = st[l] + st[r];
    }

    void propagate(int u, int i, int j, ll x)
    {
        if (x == 1) st[u] = j - i + 1;
        if (x == 2) st[u] = 0;
        if (x == 3) st[u] = j - i + 1 - st[u];
        if (i != j)
        {
            int l1 = lazy[u * 2 + 1], l2 = lazy[u * 2 + 2];
            if (x == 1 || x == 2) lazy[u * 2 + 1] = x, lazy[u * 2 + 2] = x;
            else lazy[u * 2 + 1] = 3 - l1, lazy[u * 2 + 2] = 3 - l2;
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return 0;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return x + y;
    }

    void update(int a, int b, ll value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = st[l] + st[r];
        }
    }

public:
    STL(vector<ll> &v)
    {
        arr = v; n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

int T, N, M, S, Q, a, b;
string aux;
vector<ll> A;
char type;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case " << t + 1 << ":\n";

        cin >> M; A.clear();
        rep(_, M)
        {
            cin >> S >> aux;
            N += (S * aux.size());
            rep(j, S) rep(i, aux.size()) A.push_back(aux[i] - '0');
        }

        STL stl(A);

        cin >> Q; int cnt = 0;
        rep(_, Q)
        {
            cin >> type >> a >> b;
            if (type == 'F') stl.update(a, b, 1);
            if (type == 'E') stl.update(a, b, 2);
            if (type == 'I') stl.update(a, b, 3);
            if (type == 'S')
                cout << 'Q' << ++cnt << ": " << stl.query(a, b) << '\n';
        }
    }
}