#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)


struct Node
{
    int l, r, a;
    Node() : l(0), r(0), a(0) {}
    Node(int v) : l(v), r(v), a(v) {}
    Node(const Node &n1, const Node &n2)
    {
        l = max(n1.l, n1.a + n2.l);
        r = max(n2.r, n2.a + n1.r);
        a = n1.a + n2.a;
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

int n, x;
vector<Node> v;
vector<int> L, R;

int main()
{
    cin >> n;
    rep(i, n)
    {
        cin >> x;
        v.emplace_back(x);
    }

    stack<pair<int, int>> sl; L.assign(n, 0);
    rep(i, n)
    {
        while (!sl.empty() && sl.top().first <= v[i].a) sl.pop();
        if (!sl.empty()) L[i] = sl.top().second + 1;
        sl.emplace(v[i].a, i);
    }

    stack<pair<int, int>> sr; R.assign(n, n);
    rep(i, n)
    {
        while (!sr.empty() && sr.top().first <= v[n - i - 1].a) sr.pop();
        if (!sr.empty()) R[n - i - 1] = sr.top().second;
        sr.emplace(v[n - i - 1].a, n - i - 1);
    }

    ST<Node> st(v);

    int ans = 0;
    rep(i, n)
    {
        Node l = st.query(L[i], i), r = st.query(i + 1, R[i]);
        ans = max({ans, l.r, r.l, l.r + r.l});
    }

    cout << ans << '\n';
}