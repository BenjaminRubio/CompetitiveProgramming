#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second


struct Node
{
    int v;
    Node() : v(0) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) : v(max(a.v, b.v)) {}
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
set<int> S;
map<int, int> M;
vector<pair<int, pair<int, int>>> L;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    L.resize(N);
    rep(i, N) cin >> L[i].ff;
    rep(i, N) { cin >> L[i].ss.ff; S.insert(L[i].ss.ff); }
    rep(i, N) cin >> L[i].ss.ss;

    int id = 0;
    for (int x : S) M[x] = id++;

    sort(L.rbegin(), L.rend());

    vector<Node> v(id);
    ST<Node> st(v);

    queue<pair<int, int>> Q;
    int ans = 0, l = -1;
    rep(i, N)
    {
        if (L[i].ff != l) while (!Q.empty())
        {
            int p = st.query(Q.front().ff, Q.front().ff + 1).v;
            st.set_point(Q.front().ff, max(p, Q.front().ss)), Q.pop();
        }
        if (st.query(M[L[i].ss.ff] + 1, id).v > L[i].ss.ss) ans++;
        else Q.emplace(M[L[i].ss.ff], L[i].ss.ss);
        l = L[i].ff;
    }

    cout << ans << '\n';
}