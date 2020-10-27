#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct RH
{
	int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
	vector<int> h[2], p[2];
	RH(string& s)
    {
        int N = s.size(); rep(k, 2)
        {
            h[k].resize(N + 1), p[k].resize(N + 1);
			h[k][0] = 0, p[k][0] = 1; ll b = 1;
			rep(i, N + 1) if (i)
            {
				h[k][i] = (h[k][i - 1] + b * s[i - 1]) % M[k];
				p[k][i] = (1LL * p[k][i - 1] * P[k]) % M[k];
			    b = (b * B) % M[k];
			}
		}
	}
	ll get(int l, int r)
    {
		ll h0 = (h[0][r] - h[0][l] + M[0]) % M[0];
		h0 = (1LL * h0 * p[0][l]) % M[0];
		ll h1 = (h[1][r] - h[1][r] + M[1]) % M[1];
		h1 = (1LL * h1 * p[1][l]) % M[1];
		return (h0 << 32) | h1;
	}
};