
// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
pl euclid(ll A, ll B)
{
	if (!B) return {1, 0};
	pl p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0, M) such that Ax = 1 mod M
ll minv(ll A, ll M)
{
	pl p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
	return p.ff + (p.ff < 0) * M;
}

// find (x, y)'s such that Ax + By = R where R is multiple of gcd(A, B);
pair<pl, pl> diophantine(ll A, ll B, ll R)
{
	ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
	tie(x, y) = euclid(A, B); x *= R, y *= R;
	assert(A * x + B * y == R);
	return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}
