#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N; P a, b, p;

int main()
{
    cin >> a >> b >> N;
    while (N-- && cin >> p)
    {
        ll dir = (b - a) ^ (p - a);
        if (dir > 0) cout << "I\n";
        else if (dir < 0) cout << "D\n";
        else cout << "C\n";
    }
}