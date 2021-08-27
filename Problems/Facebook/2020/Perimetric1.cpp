#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ff first
#define ss second

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

const ll MOD = 1e9 + 7;

inline ll mod(ll x, ll m) { return ((x %= m) < 0) ? x + m : x; }
inline ll mul(ll x, ll y, ll m) { return (x * y) % m; }
inline ll add(ll x, ll y, ll m) { return (x + y) % m; }

ll T, N, K, W, A, B, C, D;

int main()
{
    cin >> T;
    rep(test, T)
    {
        cout << "Case #" << test + 1 << ": ";

        cin >> N >> K >> W;

        vector<ll> L(N), H(N);
        rep(i, K) cin >> L[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            L[i] = mod(mul(A, L[i - 2], D) + mul(B, L[i - 1], D) + mod(C, D), D) + 1;

        rep(i, K) cin >> H[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            H[i] = mod(mul(A, H[i - 2], D) + mul(B, H[i - 1], D) + mod(C, D), D) + 1;

        vector<pair<ll, pair<ll, ll>>> E;
        rep(i, N)
        {
            E.emplace_back(L[i], make_pair(0, H[i]));
            E.emplace_back(L[i] + W, make_pair(1, H[i]));
        }

        sort(E.begin(), E.end());

        mint<MOD, 0> ans(1), P(0);
        ll l = L[0];
        multiset<ll, greater<ll>> s;
        for (auto &e : E)
        {
            ll M = !s.empty() ? *s.begin() : 0;
            if (e.ss.ff == 0)
            {
                P += mint<MOD, 0>(2ll * max(e.ss.ss - M, 0ll) + 2ll * min(e.ff + W - l, W));
                ans *= P, l = e.ff + W;
                s.insert(e.ss.ss);
            }
            if (e.ss.ff == 1) s.erase(s.find(e.ss.ss));
        }

        cout << int(ans) << '\n';
    }
}