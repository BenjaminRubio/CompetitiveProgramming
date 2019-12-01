#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

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

struct XOR
{
    pair<ll, ll> value;
    XOR() { value = {0LL, 0LL}; }
    XOR(pair<ll, ll> x) { value = x; }
    XOR(const XOR &a,
        const XOR &b)
    {
        value = {a.value.first ^ b.value.first, a.value.second ^ b.value.second};
    }
};

int n, q, c, p, k, x;
vector<XOR> colors_;
vector<XOR> colors;
vector<vector<int>> g;

vector<bool> visited;
vector<pair<int, int>> limits;
int counter = 0;

void dfs(int u)
{
    colors.push_back(colors_[u]);
    limits[u].first = counter++;
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v])
            dfs(v);
    limits[u].second = counter;
}

int main()
{
    cin >> n >> q;

    colors_.resize(n);
    rep(i, n)
    {
        cin >> c;
        if (c < 50)
            colors_[i] = {{1LL << c, 0LL}};
        else
            colors_[i] = {{0LL, 1LL << (c - 50)}};
    }

    g.assign(n, {});
    rep(i, n - 1)
    {
        cin >> p;
        g[p - 1].push_back(i + 1);
    }

    visited.assign(n, false);
    limits.resize(n);
    dfs(0);

    ST<XOR> st(colors);

    rep(i, q)
    {
        cin >> k >> x;

        if (k == 0)
        {
            XOR result = st.query(limits[x - 1].first, limits[x - 1].second);
            int ans = 0;
            rep(i, 60)
            {
                if ((1LL << i) & result.value.first)
                    ans++;
                if ((1LL << i) & result.value.second)
                    ans++;
            }
            cout << ans << '\n';
        }
        else
        {
            if (k < 50)
                st.set_point(limits[x - 1].first, {{1LL << k, 0LL}});
            else
                st.set_point(limits[x - 1].first, {{0LL, 1LL << (k - 50)}});
        }
    }
}