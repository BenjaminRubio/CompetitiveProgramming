#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)


struct DSU
{
	vector<int> p;
    DSU(int N) : p(N, -1) {}
	int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -p[get(x)]; }
	void unite(int x, int y)
    {
		x = get(x), y = get(y);
        if (x == y) return;
		if (p[x] > p[y]) swap(x,y);
		p[x] += p[y], p[y] = x;
	}
};
