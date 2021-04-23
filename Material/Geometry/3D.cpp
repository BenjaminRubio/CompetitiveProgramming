
const db PI = acos(-1.0L);
const db EPS = 1e-12;

// POINT 3D

struct P
{
    db x, y, z;
    P() {}
    P(db x, db y, db z) : x(x), y(y), z(z) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const db &c) const { return P(x * c, y * c, z * c); }
    P operator/(const db &c) const { return P(x / c, y / c, z / c); }
    P operator^(const P &p) const
    {
        return P(y * p.z - z * p.y, 
                 z * p.x - x * p.z,
                 x * p.y - y * p.x);
    }
    db operator*(const P &p) const { return x * p.x + y * p.y + z * p.z; }
    db operator%(const P &p) const
    {
        return acos((*this) * p) / (norm() * p.norm());
    }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) + abs(y - p.y) + abs(z - p.z) < EPS;
    }

    db norm() const { return sqrt(norm2()); }
    db norm2() const { return x * x + y * y + z * z; }
    P unit() { return (*this) / norm(); }
};
P polar(db r, db a, db b)
{
    return P(r * cos(a) * cos(b), r * cos(a) * sin(b), r * sin(a));
}
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y >> p.z; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ", " << p.z << ')';
}

// ARCS

bool in_arc(P &a, P &b, P &n, P &p)
{
    db ab = a % b;
    db ap = a % p;
    P c = (a * cos(ap) + (n ^ a) * sin(ap));
    return ab > ap && p == c;
}

bool find_intersection(P &a1, P &b1, P &a2, P &b2, db &angle)
{
    P n1 = (a1 ^ b1).unit(), n2 = (a2 ^ b2).unit(), i = (n1 ^ n2);
    if (i.norm() < EPS) return false;
    i = i.unit() * a1.norm();
    if (in_arc(a1, b1, n1, i) and in_arc(a2, b2, n2, i))
    {
        angle = a1 % i;
        return true;
    }
    i = i * -1.;
    if (in_arc(a1, b1, n1, i) and in_arc(a2, b2, n2, i))
    {
        angle = a1 % i;
        return true;
    }
    return false;
}