#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

struct MIN
{
    ll v;
    MIN() { v = 1e18; } // neutro
    MIN(ll v) : v(v) {}
    MIN(const MIN &a, const MIN &b) { v = min(a.v, b.v); }
};

template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vl &arr, int N) : n(N), t(N * 2)
    {
        rep(i, n) t[i + n] = node(arr[i]);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
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

ll X, N;
vl V, S, D, C;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> X >> N;

    V.resize(N);
    rep(i, N) cin >> V[i];

    S.assign(N, 0);
    rep(i, N) S[i] = (i ? S[i - 1] : 0ll) + V[i];

    ST<MIN> st(S, N);

    ll prev = 0, acc = 0;
    D.assign(N + 1, 0); C.assign(N + 1, 0);
    rep(i, N)
    {
        int l = i, r = N;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (st.query(i, m + 1).v < acc) r = m;
            else l = m + 1;
        } int j = l;
        prev += j - i;

        if (X >= 0)
        {
            l = i, r = N;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (st.query(i, m + 1).v < acc - X) r = m;
                else l = m + 1;
            } int k = l;
            D[i] += (k - j), D[j + 1] -= (k - j);
        }
        else
        {
            l = i, r = j;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (st.query(m, j).v >= acc - X) r = m;
                else l = m + 1;
            } int k = l;
            D[i] += j, D[k] -= j;
            C[i]++, C[k]--;
        }

        acc += V[i];
    }

    ll ans = 0, aux = 0, caux = 0;
    if (X >= 0) rep(i, N) aux += D[i], ans = max(ans, aux + prev);
    else rep(i, N) aux += D[i], caux += C[i], ans = max(ans, prev - (aux - (ll)i * caux));

    cout << ans << '\n';
}
