#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Node
{
    int v;
    Node() { v = 1e9; }
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = min(a.v, b.v); }
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

int S, N, A, B;
priority_queue<pair<par, int>, vector<pair<par, int>>, greater<pair<par, int>>> Q, C;

int main()
{
    cin >> S;
    rep(i, S) { cin >> A >> B; Q.emplace(make_pair(B, A), i); }

    cin >> N;
    rep(i, N) { cin >> A >> B; C.emplace(make_pair(B, A), i); }

    vector<Node> aux(100001);
    ST<Node> st(aux);

    vector<int> ans(N);
    rep(_, N)
    {
        auto e = C.top(); C.pop();
        while (!Q.empty() && Q.top().ff.ff <= e.ff.ff)
        {
            auto q = Q.top(); Q.pop();
            int prev = st.query(q.ff.ss, q.ff.ss + 1).v;
            st.set_point(q.ff.ss, Node(min(prev, q.ss)));
        }
        ans[e.ss] = st.query(e.ff.ss, 100001).v;
    }

    ll d = 0;
    rep(i, N) d += ans[i] + 1;

    cout << d << '\n';
}