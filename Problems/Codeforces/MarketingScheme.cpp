#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, l, r;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> l >> r;

		if (r >= l * 2) cout << "NO\n";
		else cout << "YES\n";
	}
}