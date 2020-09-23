#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back

struct Node
{
    int v, l, r;
    Node() : v(0), l(1), r(1) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    {
        v = a.v + b.v;
    }
};

template <class node>
struct PST 
{
    int cnt = 0, n;
	vector<node> st; vector<int> rt;

	int copy(int u) { st[cnt] = st[u]; return cnt++; }

	node query(int u, int a, int b, int i, int j)
    {
        if (j < a || b < i) return node();
		if (a <= i && j <= b) return st[u];
		int m = (i + j) / 2, l = st[u].l, r = st[u].r;
		return node(query(l, a, b, i, m), query(r, a, b, m + 1, j), 0, 0);
	}

	int update(int u, int p, node v, int i, int j)
    {
		if (j < p || p < i) return u;
		int x = copy(u), m = (i + j) / 2;
		if (i == j) { st[x] = v; return x; }
        int l = st[x].l = update(st[x].l, p, v, i, m);
        int r = st[x].r = update(st[x].r, p, v, m + 1, j);
        st[x] = node(st[st[x].l], st[st[x].r], l, r); return x;
	}
    
	int build(vector<node> &arr, int i, int j)
    {
		int u = cnt++, m = (i + j) / 2;
		if (i == j) { st[u] = arr[i]; return u; }
		int l = st[u].l = build(arr, i, m);
        int r = st[u].r = build(arr, m + 1, j);
		st[u] = node(st[st[u].l], st[st[u].r], l, r); return u;
	}

    PST(vector<node> &arr)
    {
        n = arr.size(); st.resize(2e7);
        rt.pb(build(arr, 0, n - 1));
    }

	void update(int t, int p, node v) { rt.pb(update(rt[t], p, v, 0, n - 1)); }

	node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};

vector<Node> v;

int main()
{
    v.resize(10, 1);
    PST<Node> pst(v);

    cerr << pst.query(0, 0, 9).v << '\n' << '\n';

    pst.update(0, 0, Node(0));

    cerr << pst.query(0, 0, 9).v << '\n';
    cerr << pst.query(1, 0, 9).v << '\n' << '\n';

    pst.update(1, 0, Node(0));

    cerr << pst.query(0, 0, 9).v << '\n';
    cerr << pst.query(1, 0, 9).v << '\n';
    cerr << pst.query(2, 0, 9).v << '\n' << '\n';
}