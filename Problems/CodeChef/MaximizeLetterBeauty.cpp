#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct Node
{
    ll l, r, s;
    Node() : l(0), r(0), s(0) {}
    Node(ll x) : l(max(x, 0ll)), r(max(x, 0ll)), s(x) {}
    Node(const Node &a, const Node &b)
    {
        l = max(a.l, a.s + b.l);
        r = max(a.r + b.s, b.r);
        s = a.s + b.s;
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(const vector<node> &arr)
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

ll T, N, Q, l, r, x;
char op;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;

        vector<Node> B;
        rep(_, N) { cin >> x; B.emplace_back(x); }

        ST<Node> st(B);

        rep(_, Q)
        {
            cin >> op >> l >> r; l--;

            if (op == 'Q')
            {
                ll L = st.query(0, l).r;
                ll S = st.query(l, r).s;
                ll R = st.query(r, N).l;

                cout << L + S + R << '\n';
            }
            else st.set_point(l, Node(r));
        }
    }
}