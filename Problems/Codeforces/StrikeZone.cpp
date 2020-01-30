#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

struct Node
{
    int l, r, v, s;
    Node()
    {
        l = r = v = s = 0;
    }
    Node(int x)
    {
        l = r = v = s = x;
    }
    Node(const Node &a, const Node &b)
    {
        l = max(a.l, a.s + b.l);
        r = max(a.r + b.s, b.r);
        v = max({a.v, a.r + b.l, b.v});
        s = a.s + b.s;
    }
};

struct SegmentTree {
	vector<Node> ST;
	int N;

	SegmentTree(int N) : N(N) {
		ST.resize(4 * N, 0);
	}

	void update(int i, int val) {
		return update(1, 0, N - 1, i, val);
	}

	void update(int n, int l, int r, int i, int val) {
		if(i < l || r < i) return;
		if(l == r) {
			ST[n] = Node(val);
			return;
		}

		update(n << 1, l, (l + r) / 2, i, val);
		update(n << 1 | 1, (l + r) / 2 + 1, r, i, val);

		ST[n] = Node(ST[n << 1], ST[n << 1 | 1]);
	}

	int query() {
		return ST[1].v;
	}
};

int n1, n2, x, y, c1, c2;
set<int> sx, sy;
map<int, int> mx, my;
vector<pair<pair<int, int>, int>> v;
vector<int> pos, val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n1;
    rep(i, n1)
    {
        cin >> x >> y;
        sx.insert(x);
        sy.insert(y);
        v.push_back({{x, y}, 0});
    }

    cin >> n2;
    rep(i, n2)
    {
        cin >> x >> y;
        sx.insert(x);
        sy.insert(y);
        v.push_back({{x, y}, 1});
    }

    cin >> c1 >> c2;

    int nx = 0, ny = 0;
    for (int x : sx) mx[x] = nx++;
    for (int y : sy) my[y] = ny++;

    pos.resize(nx);
    val.resize(nx);
    for (auto e : v)
    {
        x = e.ff.ff;
        y = e.ff.ss;
        pos[mx[x]] = my[y];
        if (!e.ss) val[mx[x]] = c1;
        else val[mx[x]] = -1 * c2;
    }

    int ans = 0;
    rep(i, nx)
    {
        SegmentTree st(ny);
        repx(j, i, nx)
        {
            st.update(pos[j], val[j]);
            ans = max(ans, st.query());
        }
    }

    cout << ans << '\n';
}