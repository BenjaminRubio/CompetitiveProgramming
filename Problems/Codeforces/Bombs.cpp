#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    static int const neutro = 0;
    static int op(int x, int y) { return max(x, y); }
};

template <class t>
class STL
{
    vector<int> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, int x)
    {
        st[u] += x;
        if (i != j)
        {
            lazy[u * 2 + 1] += x;
            lazy[u * 2 + 2] += x;
        }
        lazy[u] = 0;
    }

    int query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        int x = query(a, b, l, i, m);
        int y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, int value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

public:
    STL(vector<int> &v)
    {
        arr = v; n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    int query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, int value) { update(a, b, value, 0, 0, n - 1); }
};

int N, x;
vector<int> P;
priority_queue<pair<int, int>> Q;

int main()
{
    cin >> N;

    P.resize(N);
    rep(i, N) { cin >> x; P[x - 1] = i; }

    vector<int> v(N, 0);
    STL<Node> stl(v);

    cout << N << ' ';

    int ans = N;
    stl.update(0, P[ans - 1], 1);
    rep(i, N - 1)
    {
        cin >> x;
        stl.update(0, x - 1, -1);

        while (stl.query(0, N - 1) <= 0)
        {
            ans--;
            stl.update(0, P[ans - 1], 1);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}