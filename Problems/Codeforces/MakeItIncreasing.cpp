#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, K;
vector<int> A, B;

int LIS(vector<int> &v)
{
	vector<int> L; int S = 0;
	for(int x : v)
    {
		int i = upper_bound(L.begin(), L.end(), x) - L.begin();
		if(i == S) L.push_back(x), S++;
		else L[i] = x;
	}
	return S;
}

int main()
{
    cin >> N >> K;

    A.resize(N);
    rep(i, N) cin >> A[i];

    B.resize(K);
    rep(i, K) { cin >> B[i]; B[i]--; }

    bool pos = 1;
    rep(i, K) if (i && (A[B[i]] - A[B[i - 1]] < B[i] - B[i - 1])) pos = 0;

    if (!pos) { cout << -1 << '\n'; return 0; }

    int ans = 0, i = 0; B.push_back(N), A.push_back(INT_MAX);
    pair<int, int> pp = {-1e6, -1};
    for (int j : B)
    {
        pair<int, int> p = pp; vector<int> v;
        for (int k = i; k < j; k++) if (A[k] < A[j] && (A[j] - A[k] >= j - k))
        {
            if (A[k] > p.ff && (A[k] - p.ff >= k - p.ss)) v.push_back(A[k] - k);
        }
        ans += LIS(v), i = j + 1, pp = {A[j], j};
    }

    cout << N - K - ans << '\n';
}