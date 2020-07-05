#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N;

ll comp(ll n)
{
	ll factors = 0;
	for (ll d = 2; d * d <= n; d++) while (n % d == 0)
    {
        factors += d;
        if ((n /= d) == 1) return factors;
    }
	if (n > 1) factors += n;
	return factors;
}

int main()
{
    while (cin >> N && N != 4)
    {
        int c = 1;
        while (1)
        {
            ll aux = comp(N);
            if (aux == N) break;
            N = aux, c++;
        }
        cout << N << ' ' << c << '\n';
    }
}