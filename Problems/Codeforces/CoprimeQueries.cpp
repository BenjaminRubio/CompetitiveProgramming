#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

const int MAXN = 1e5;
int n, q, l, r, x;
vector<int> a;
vector<int> p;
map<int, int> m;
vector<vector<int>> d;
vector<vector<int>> arr;
vector<bool> is_prime;
vector<int> mob;
vector<int> nsq;

int count_coprimes(int l, int r, int x)
{
	int ans = 0;
	for (int v : d[x])
	{
		int i, j;
		int id = m[v];

		int low = 0;
		int high = arr[id].size();
		while (low < high)
		{
			int mid = (low + high) / 2;

			if (arr[id][mid] >= l)
				high = mid;
			else
				low = mid + 1;
		}

		i = low;

		low = 0;
		high = arr[id].size();
		while (low < high)
		{
			int mid = (low + high) / 2;

			if (arr[id][mid] > r)
				high = mid;
			else
				low = mid + 1;
		}

		j = low;

		ans += mob[v] * (j - i + 1);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> q;

    a.resize(n);
    rep(i, n) cin >> a[i];

	is_prime.assign(MAXN + 1, true);
    mob.assign(MAXN + 1, 0); mob[1] = 1;
	repx(i, 2, MAXN + 1)
	{
		if (is_prime[i])
		{
			p.push_back(i);
			mob[i] = -1;
		}
		for (int j = 0; j < (int)p.size() and p[j] * i < MAXN + 1; j++)
		{
			is_prime[p[j] * i] = false;
			mob[p[j] * i] = mob[p[j]] * mob[i];
			if(i % p[j] == 0)
			{
				mob[i * p[j]] = 0;
				break;
			}
		}
	}

	int id = 1;
	nsq.push_back(1);
	m[1] = 0;
	repx(i, 2, MAXN + 1)
	{
		bool is = true;
		for (int v : p)
		{
			if (v > floor(sqrt(i))) break;
			if (i % (v * v) == 0) 
			{
				is = false;
				break;
			}
		}

		if (is)
		{
			nsq.push_back(i);
			m[i] = id++;
		}
	}

	d.resize(MAXN + 1);
	rep(i, nsq.size())
		for (int j = 1; j * nsq[i] <= MAXN; j++) d[nsq[i] * j].push_back(nsq[i]);

	arr.resize(nsq.size());
	rep(i, n)
	{
		vector<int> f;
		int aux = a[i];
		for (int v : p)
		{
			if (v > a[i]) break;
			if (aux % v == 0) f.push_back(v);
			while (aux % v == 0) if ((aux /= v) == 1)
				goto next;
		}

		next:

		rep(j, 1 << (int)f.size())
		{
			int y = 1;
			rep(k, f.size()) if ((1 << k) & j) y *= f[k];
			
			arr[m[y]].push_back(i);
		}
	}

	rep(_, q)
	{
		cin >> l >> r >> x;
		l--; r--;

		int low = 0;
		int high = r - l + 1;
		while (low < high)
		{
			int mid = (low + high) / 2;

			if (count_coprimes(r - mid, r, x))
				high = mid;
			else
				low = mid + 1;
		}

		if (low == r - l + 1) cout << -1 << '\n';
		else cout << r - low + 1 << '\n';
	}
}
