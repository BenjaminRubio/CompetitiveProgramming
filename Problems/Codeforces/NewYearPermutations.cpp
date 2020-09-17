#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

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

int T, N;
vector<int> A;

ll K, F[51], DP[51], INF = LLONG_MAX;

ll add(const ll &a, const ll &b) { return (a > INF - b) ? INF : a + b; }
ll mul(const ll &a, const ll &b) { return (a > INF / b) ? INF : a * b; }

ll f(int i) { return i >= 0 ? F[i] : 1ll; }

ll dp(int i)
{
    if (i == N) return 1;
    if (DP[i] != -1) return DP[i];

    ll ans = 0;
    repx(j, i, N) ans = add(ans, mul(dp(j + 1), f((j - i + 1) - 2)));
    return DP[i] = ans;
}

void block(int i, int j, ll R)
{
    if (i == j) return;
    vector<bool> on(j - i + 1, 0); on[j - i] = 1;
    DSU d(j - i + 1); d.unite(0, j - i);
    repx(k, i + 1, j) rep(l, j - i + 1) if (!d.sameSet(k - i, l) && !on[l])
    {
        if (R > f(j - k - 1)) R -= f(j - k - 1);
        else { A[k] = l + i + 1; d.unite(k - i, l); on[l] = 1; break; }
    }
    rep(l, j - i) if (!on[l]) A[j] = l + i + 1;
}

void get_size(int i)
{
    if (i == N) return;

    int j = i;
    while (j < N - 1 && mul(f((j - i + 1) - 2), dp(j + 1)) < K)
        K -= mul(f((j - i + 1) - 2), dp(j + 1)), j++;
    block(i, j, (K - 1) / dp(j + 1) + 1);
    K -= mul((K - 1) / dp(j + 1), dp(j + 1));
    A[i] = j + 1;
    get_size(j + 1);
}

int main()
{
    F[0] = 1; rep(i, 50) F[i + 1] = mul(F[i], i + 1);

    cin >> T;
    while (T--)
    {
        memset(DP, -1, sizeof DP);

        cin >> N >> K;

        if (K > dp(0)) { cout << -1 << '\n'; continue; }

        A.assign(N, 0); get_size(0);
        rep(i, N) cout << A[i] << ' ';
        cout << '\n';
    }
}