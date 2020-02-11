#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define forall(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)
typedef long long ll;

int n, l;
vector<vector<ll>> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	while (cin >> n)
    {
        arr.clear();
        arr.resize(n);
		rep(i, n)
        {
			cin >> l;
			arr[l - 1].push_back(0);
		}
		
		ll ans = 0, d = 1;
		rep(i, n)
        {
			forall(it, arr[n - i - 1]) if (!*it) ans += *it = d;
			if (i < n - 1) rep(j, arr[n - i - 1].size() / 2)
            {
				arr[n - i - 2].push_back(arr[n - i - 1][2 * j] + arr[n - i - 1][2 * j + 1]);
				d = max({d, arr[n - i - 1][2 * j], arr[n - i - 1][2 * j + 1]});
			}
		}
		
        cout << ans << '\n';
	}
}