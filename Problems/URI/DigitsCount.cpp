#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int A, B, N, C[10], P;
bool flag;

int main()
{
	while (cin >> A >> B && A)
    {
		memset(C, 0, sizeof C);

		N = B, P = 1; flag = 1;
		while (N)
        {
			int d = N % 10;

			if (N >= 10)
            {
				rep(i, 9) C[i + 1] += (N / 10) * P;
				C[0] += (N / 10 - 1) * P;
			}

			if (N >= 10) rep(i, d) C[i] += P;
			else rep(i, d - 1) C[i + 1] += P;

			if (!flag) C[d] += B - N * P + 1;
			else C[d]++, flag = 0;

			P *= 10, N /= 10;
		}

        N = A - 1, P = 1; flag = 1;
		while (N)
        {
			int d = N % 10;

			if (N >= 10)
            {
				rep(i, 9) C[i + 1] -= (N / 10) * P;
				C[0] -= (N / 10 - 1) * P;
			}

			if (N >= 10) rep(i, d) C[i] -= P;
			else rep(i, d - 1) C[i + 1] -= P;

			if (!flag) C[d] -= (A - 1) - N * P + 1;
			else C[d]--, flag = 0;

			P *= 10, N /= 10;
		}

        rep(i, 10)
        {
            if (i) cout << ' ' << C[i];
            else cout << C[i];
        }
        cout << '\n';
	}

	return 0;
}