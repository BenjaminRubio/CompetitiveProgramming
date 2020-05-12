#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = acos(-1.0L);
const double EPS = 1e-12;

typedef double T;  // can be integer
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator<(const P &p) const { return ang() < p.ang(); }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    double ang() const
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

struct Node
{
    double v;
    Node() { v = -1.; }
    Node(double v) : v(v) {}
    Node(const Node &a, const Node &b) { v = max(a.v, b.v); }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1; )
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int N;
vector<P> p;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N;

    p.resize(N);
    rep(i, N) cin >> p[i];

    double ans = -1.;
    rep(i, N)
    {
        P a = p[i];

        vector<P> v;
        rep(j, N) if (i != j) v.push_back(p[j] - a);

        sort(v.begin(), v.end());
        rep(j, N - 1) v.push_back(v[j]);

        vector<Node> d;
        rep(j, 2 * N - 2) d.emplace_back(v[j].norm());
        ST<Node> st(d);

        vector<double> v_; v_.resize(2 * N - 2);
        rep(j, 2 * N - 2) v_[j] = v[j].ang() + ((j >= N - 1) ? 2. * PI : 0.);

        int l = 0, r = 0;
        rep(j, N - 1)
        {
            double bl = v_[j] + PI / 3., br = v_[j] + 5. * PI / 3.;

            while (l < v_.size() && v_[l] < bl) l++;
            while (r < v_.size() && v_[r] < br) r++;

            ans = max(ans, min(d[j].v, st.query(l, r).v));
        }
    }

    cout << ans / 2. << '\n'; 
}