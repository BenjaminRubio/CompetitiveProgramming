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

ll T, N, K, A, B, C, D;

int main()
{
    cin >> T;
    rep(test, T)
    {
        cout << "Case #" << test + 1 << ": ";

        cin >> N >> K;

        vector<ll> L(N), W(N), H(N);
        rep(i, K) cin >> L[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            L[i] = mod(mul(A, L[i - 2], D) + mul(B, L[i - 1], D) + mod(C, D), D) + 1;

        rep(i, K) cin >> W[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            W[i] = mod(mul(A, W[i - 2], D) + mul(B, W[i - 1], D) + mod(C, D), D) + 1;

        rep(i, K) cin >> H[i];

        cin >> A >> B >> C >> D;
        repx(i, K, N)
            H[i] = mod(mul(A, H[i - 2], D) + mul(B, H[i - 1], D) + mod(C, D), D) + 1;

        mint<MOD, 0> ans(1), h(0), v(0);
        set<pair<ll, ll>> s;
        rep(i, N)
        {
            if (!s.empty())
            {
                auto it = s.lower_bound({L[i], LLONG_MAX});
                if (it != s.begin()) it--;
                else v += H[i];
                if (it->ff < L[i] && it->ss < L[i]) v += H[i];

                it = s.lower_bound({L[i] + W[i], LLONG_MAX});
                if (it != s.begin()) it--;
                else v += H[i];
                if (it->ff < L[i] + W[i] && it->ss < L[i] + W[i]) v += H[i];

                ll c = 0, A = 0, l = L[i], r = L[i] + W[i];
                queue<pair<ll, ll>> q;

                it = s.lower_bound({L[i], LLONG_MAX});
                if (it != s.begin()) it--;
                while (it != s.end())
                {
                    if (it->ff > L[i] + W[i]) break;
                    if (it->ff < L[i] && it->ss >= L[i])
                    {
                        l = it->ff, r = max(r, it->ss);
                        q.push(*it);
                        A += min(L[i] + W[i], it->ss) - L[i];
                        c += (it->ss < L[i] + W[i]);
                    }
                    if (it->ff >= L[i])
                    {
                        r = max(r, it->ss);
                        q.push(*it);
                        A += min(L[i] + W[i], it->ss) - it->ff;
                        c += (it->ff > L[i]) + (it->ss <= L[i] + W[i]);
                    }
                    it++;
                }
                while (!q.empty()) s.erase(q.front()), q.pop();
                s.insert({l, r});

                v -= mint<MOD, 0>(H[i] * c);
                h += mint<MOD, 0>(W[i] - A);
            }
            else { v += 2 * H[i]; h += W[i]; s.insert({L[i], L[i] + W[i]}); }

            ans *= 2 * h + v;
        }

        cout << int(ans) << '\n';
    }
}