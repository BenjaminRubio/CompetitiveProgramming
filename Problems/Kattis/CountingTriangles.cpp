#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)

typedef double T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool propInt(P &a, P &b, P &c, P &d)
{
    T ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    return (ta * tb < 0 && tc * td < 0);
}

int N;
vector<P> A, B;

int main()
{
    while (cin >> N && N)
    {
        A.resize(N), B.resize(N);
        rep(i, N) cin >> A[i] >> B[i];

        int ans = 0;
        rep(i, N) repx(j, i + 1, N) repx(k, j + 1, N)
        {
            if (propInt(A[i], B[i], A[j], B[j]) &&
                propInt(A[j], B[j], A[k], B[k]) &&
                propInt(A[i], B[i], A[k], B[k])) ans++;
        }

        cout << ans << '\n';
    }
}