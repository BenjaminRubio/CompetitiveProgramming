#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

struct Matrix
{
    ll m[2][2] = {0};
    Matrix operator*(const Matrix &o) const
    {
        Matrix ans;
        rep(i, 2) rep(j, 2) rep(k, 2)
            ans.m[i][k] = (ans.m[i][k] + m[i][j] * o.m[j][k]) % MOD;
        return ans;
    }
};

struct Node
{
    Matrix v;
    Node() { v.m[0][0] = 1, v.m[1][1] = 1; }
    Node(Matrix a) { v = a; }
    Node(const Node &a, const Node &b) { v = a.v * b.v; }
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

int N, Q, p;
string S;

int main()
{
    cin >> N >> Q >> S;

    Matrix s, h, f, n, u, i;
    s.m[0][0] = 0, s.m[0][1] = 1, s.m[1][0] = 0, s.m[1][1] = 1;
    h.m[0][0] = 1, h.m[0][1] = 0, h.m[1][0] = 1, h.m[1][1] = 0;
    f.m[0][0] = 0, f.m[0][1] = 1, f.m[1][0] = 1, f.m[1][1] = 0;
    n.m[0][0] = 1, n.m[0][1] = 0, n.m[1][0] = 0, n.m[1][1] = 1;
    u.m[0][0] = 19, u.m[0][1] = 7, u.m[1][0] = 6, u.m[1][1] = 20;
    i.m[0][0] = 1, i.m[0][1] = 0, i.m[1][0] = 0, i.m[1][1] = 0;

    vector<Node> v; v.emplace_back(i);
    for (char c : S)
    {
        if (c == 'S' || c == 'D') v.emplace_back(s);
        else if (c == 'H') v.emplace_back(h);
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') v.emplace_back(f);
        else if (c == '?') v.emplace_back(u);
        else v.emplace_back(n);
    }

    ST<Node> st(v);

    cout << st.query(0, N + 1).v.m[0][0] << '\n';
    rep(_, Q)
    {
        char c; cin >> p >> c;

        if (c == 'S' || c == 'D') st.set_point(p, Node(s));
        else if (c == 'H') st.set_point(p, Node(h));
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') st.set_point(p, Node(f));
        else if (c == '?') st.set_point(p, Node(u));
        else st.set_point(p, Node(n));

        cout << st.query(0, N + 1).v.m[0][0] << '\n';
    }
}