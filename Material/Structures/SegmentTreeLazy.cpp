#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int v, v_ = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(a.v + b.v) {}
    Node(int x, int i, int j, const Node &b)
    {
        v = b.v + (j - i + 1) * x;
    }
};

template <class node>
class STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }

    void propagate(int u, int i, int j, int x)
    {
        st[u] = node(x, i, j, st[u]);
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
    STL(vector<node> &v) : n(v.size())
    {
        st.resize(n * 4 + 5);
        build(0, 0, n - 1, v);
    }

    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};