#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef long long ll;

struct SUM
{
    ll value;
    SUM() { value = 0; }
    SUM(ll x) { value = x; }
    SUM(const SUM &a,
        const SUM &b)
    {
        value = a.value + b.value;
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
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int n, q, s, t;
ll x, u;
vector<SUM> a;
vector<SUM> ex;

int main()
{
    cin >> n;
    a.resize(n);
    rep(i, n)
    {
        cin >> x;
        a[i] = SUM(x);
    }

    ST<SUM> st(a);

    cin >> q;
    rep(i, q)
    {
        cin >> s >> t >> u;
        SUM prev = st.query(t - 1, t);
        if (prev.value > u)
            st.set_point(t - 1, SUM(prev.value - u));
        else if (s != t)
            st.set_point(t - 1, SUM(0LL));

        cout << st.query(0, n).value << '\n';
    }
}