#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a;

bool square(int a)
{
	bool ans = 1;
	for (int d = 2; d * d <= a; d++)
    {
        int aux = 0;
		while (a % d == 0) {
			aux += 1;
            a /= d;
		}
        if (aux & 1) ans = 0;
	}
	if (a > 1) ans = 0;
	return ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        bool flag = 0;
        rep(_, N)
        {
            cin >> a;
            if (!square(a) && !flag)
            {
                cout << "YES\n";
                flag = 1;
            }
        }

        if (!flag) cout << "NO\n";
    }
}