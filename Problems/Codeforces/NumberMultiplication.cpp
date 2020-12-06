#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<pair<long long, long long>> vpl;
typedef vector<int> vi;

ul modMul(ul a, ul b, const ul mod) {
	ll ret = a*b-mod*(ul)((ld)a*b/mod);
	return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod) {
	if (b == 0) return 1;
	ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);
	return b&1 ? modMul(res,a,mod) : res;
}

bool prime(ul n) {
	if (n < 2 || n % 6 % 4 != 1) return n-2 < 2;
	ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n>>s;
	for (auto &a : A) {
		ul p = modPow(a,d,n), i = s;
		while (p != 1 && p != n-1 && a%n && i--) p = modMul(p,p,n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

template<int SZ> struct Sieve { 
	bitset<SZ> pri; vi pr;
	Sieve() {
		pri.set(); pri[0] = pri[1] = 0;
		for (int i = 4; i < SZ; i += 2) pri[i] = 0;
		for (int i = 3; i * i < SZ; i += 2) if (pri[i])
			for (int j = i * i; j < SZ; j += i*2) pri[j] = 0;
		rep(i, SZ) if (pri[i]) pr.pb(i);
	}
};

Sieve<1<<20> S;
ul pollard(ul n) {
	auto f = [n](ul x) { return (modMul(x,x,n)+1)%n; };
	if (!(n&1)) return 2;
	for (ul i = 2;;++i) {
		ul x = i, y = f(x), p;
		while ((p = __gcd(n+y-x,n)) == 1) x = f(x), y = f(f(y));
		if (p != n) return p;
	}
}
vpl factor(ll d) {
	vpl res; 
	for (auto &t : S.pr) {
		if ((ul)t*t > d) break;
		if (d%t == 0) {
			res.pb({t,0}); 
			while (d%t == 0) d /= t, res.back().second ++;
		}
	}
	if (prime(d)) res.pb({d,1}), d = 1;
	if (d == 1) return res;
	ll c = pollard(d); d /= c; if (d > c) swap(d,c);
	if (c == d) res.pb({c,2});
	else res.pb({c,1}), res.pb({d,1});
	return res;
}

int N, M, K;
vector<ll> C;

int main()
{
    cin >> M >> N >> K;

    C.resize(N);
    rep(i, N) cin >> C[i];

    set<ll> s;
    rep(i, N)
    {
        vpl p = factor(C[i]);
        for (auto &e : p) s.insert(e.first);
    }

    for (ll p : s) cout << p << ' ';
    cout << '\n';
}