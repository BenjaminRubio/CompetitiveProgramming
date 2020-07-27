#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Node
{
    int v;
    Node() { v = INT_MIN; }
    Node(int v) : v(v) {}
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

int N, Q, l, r;
vector<int> A;
vector<Node> cnt;
set<int> s;
map<int, pair<int, int>> M;

int main()
{
    while (cin >> N && N)
    {
        cin >> Q;

        s.clear();

        A.resize(N);
        rep(i, N)
        {
            cin >> A[i];
            if (!s.count(A[i])) { M[A[i]] = {i, i}; s.insert(A[i]); }
            else M[A[i]].ss++;
        }

        cnt.resize(N);
        rep(i, N) cnt[i] = Node(M[A[i]].ss - M[A[i]].ff + 1);

        ST<Node> st(cnt);

        rep(_, Q)
        {
            cin >> l >> r; l--, r--;
            int vl = min(M[A[l]].ss, r) - l + 1, vr = r - max(M[A[r]].ff, l) + 1;
            Node ans = st.query(M[A[l]].ss + 1, M[A[r]].ff);
            if (vl >= vr && vl >= ans.v) cout << vl << '\n';
            else if (vr >= vl && vr >= ans.v) cout << vr << '\n';
            else cout << ans.v << '\n';
        }
    }
}