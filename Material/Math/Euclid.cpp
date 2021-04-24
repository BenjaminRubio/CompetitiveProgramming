
// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
pair<ll, ll> euclid(ll A, ll B)
{
	if (!B) return {1, 0};
	auto p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0,B) such that Ax = 1 mod M
ll mulinv(ll A, ll M)
{
	auto p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
	return p.ff + (p.ff < 0) * M;
}

// find (x, y)'s such that Ax + By = R where R is multiple of gcd(A, B);
pair<pair<ll, ll>, pair<ll, ll>> diophantine(ll A, ll B, ll R)
{
	ll g = __gcd(A, B);
	A /= g, B /= g, R /= g;
	auto p = euclid(A, B);
	p.ff *= R; p.ss *= R;
	assert(A * p.ff + B * p.ss == R);
	return {p, {-B, A}}; // solutions: p+t*ans.snd
}
