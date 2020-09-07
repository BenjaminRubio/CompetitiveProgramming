#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll A, B, N, C, P;
bool flag;

int main()
{
	while (cin >> A >> B && A)
    {
		C = 0;

		N = B, P = 1; flag = 1;
		while (N)
        {
			int d = N & 1ll;

			if (N > 1) C += (N >> 1ll) * P;

			if (!flag && d) C += B - N * P + 1ll;
			else C += d, flag = 0;

			P <<= 1ll, N >>= 1ll;
		}

        N = A - 1ll, P = 1; flag = 1;
		while (N)
        {
			int d = N & 1ll;

			if (N > 1) C -= (N >> 1ll) * P;

			if (!flag && d) C -= (A - 1ll) - N * P + 1ll;
			else C -= d, flag = 0;

			P <<= 1ll, N >>= 1ll;
		}

        cout << C << '\n';
	}

	return 0;
}