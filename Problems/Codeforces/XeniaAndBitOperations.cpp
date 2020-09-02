#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Node
{
    int v, d;
    Node() {}
    Node(int v) : v(v), d(0) {}
    Node(const Node &a, const Node &b)
    {
        if (a.d) v = a.v ^ b.v;
        else v = a.v | b.v;
        d = !a.d;
    }
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
    node query() { return t[1]; }
};

int N, M, p, b;
vector<Node> B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    rep(_, 1 << N) { cin >> b; B.emplace_back(b); }

    ST<Node> st(B);

    rep(_, M)
    {
        cin >> p >> b;
        st.set_point(p - 1, b);
        cout << st.query().v << '\n';
    }
}