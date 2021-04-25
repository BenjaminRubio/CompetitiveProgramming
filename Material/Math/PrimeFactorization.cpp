
// Naive with precomputed primes

vi P;
vi factor(int x)
{
    vi ans;
    for (int d : P)
    {
        if (d * d > x) break;
        while (x % d == 0)
        {
            ans.pb(d);
            if ((x /= d) == 1) return ans;
        }
    }
    if (x > 1) ans.pb(x);
    return ans;
}

// Pollard Rho ( O(n^{1/4}) )

#include <MillerRabin.cpp>

ul pollard(ul n) // return some nontrivial factor of n
{
	auto f = [n](ul x) { return modMul(x, x, n) + 1; };
	ul x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1)
    {
		if (x == y) x = ++i, y = f(x);
		if ((q = modMul(prd, max(x, y) - min(x, y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}

void rec(ul n, map<ul, int> &C)
{
	if (n == 1) return;
	if (prime(n)) { C[n]++; return; }
	ul u = pollard(n); rec(u, C), rec(n / u, C);
}

vector<pair<ul, int>> factor(ul n)
{
	map<ul, int> C; rec(n, C);
	return vector<pair<ul, int>>(all(C));
}
