#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int L[31] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 
             4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444};

struct Node
{
    int v, c, d, v_ = 0;
    bool lz = false;
    Node() : d(1e6), c(0), v(-1e6) {}
    Node(int x) : v(x), c(1)
    {
        int i = 0;
        while (L[i] < x) i++;
        d = L[i] - x;
    }
    Node(const Node &a, const Node &b)
    {
        d = min(a.d, b.d);
        c = (a.d <= b.d) * a.c + (a.d >= b.d) * b.c;
    }
    Node(int x, const Node &b)
    {
        *this = b;
        v += x, d -= x, lz = 0, v_ = 0;
    }
};

template <class node>
class STL
{
    vector<node> st;
    int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }

    void propagate(int u, int i, int j, int x)
    {
        st[u] = node(x, st[u]);
        if (i != j)
        {
            st[u * 2 + 1].lz = 1, st[u * 2 + 1].v_ += x;
            st[u * 2 + 2].lz = 1, st[u * 2 + 2].v_ += x;
        }
    }

    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) propagate(u, i, j, st[u].v_);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }

    void update(int a, int b, int v, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) propagate(u, i, j, st[u].v_);
        if (a <= i && j <= b) propagate(u, i, j, v);
        else if (j < a || b < i) return;
        else
        {
            update(a, b, v, l, i, m);
            update(a, b, v, r, m + 1, j);
            st[u] = node(st[l], st[r]);
        }
    }

public:
    STL(vector<node> &v)
    {
        n = v.size();
        st.resize(n * 4 + 5);
        build(0, 0, n - 1, v);
    }

    void fix(int u, int i, int j)
    {
        if (st[u].lz) propagate(u, i, j, st[u].v_);
        if (st[u].d >= 0) return;
        if (i == j) { st[u] = node(st[u].v); return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        fix(l, i, m), fix(r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};

int N, M, x, l, r;
string t;
vector<Node> v;

int main()
{
    cin >> N >> M;

    rep(i, N) { cin >> x; v.emplace_back(x); }

    STL<Node> stl(v);
    rep(i, M)
    {
        cin >> t;
        if (t == "count")
        {
            cin >> l >> r;
            Node ans = stl.query(l - 1, r - 1);
            if (ans.d == 0) cout << ans.c << ' ';
            else cout << 0 << ' ';
        }
        else
        {
            cin >> l >> r >> x;
            stl.update(l - 1, r - 1, x);
            stl.fix(0, 0, N - 1);
        }
    }
}