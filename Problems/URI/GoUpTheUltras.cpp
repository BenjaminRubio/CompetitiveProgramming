#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<float> vfloat;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = a; i > (int)b; i--)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) // cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                  \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //                                                                       \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct SparseTable
{
    int n;
    vector<int> memo;
    vector<int> *arr;
    SparseTable(vector<int> &_arr)
    {
        arr = &_arr;
        n = arr->size();
        int maxlog = lg(n);
        memo.assign(n * (maxlog + 1), -1);
    }

    int dp(int i, int e)
    {
        int &ans = memo[e * n + i];
        if (ans != -1)
            return ans;
        if (e == 0)
            return ans = (*arr)[i];
        return ans = min(dp(i, e - 1), dp(i + (1 << (e - 1)), e - 1));
    }

    int rmq_O1(int l, int r)
    {
        int e = lg(r - l + 1);
        return min(dp(l, e), dp(r - (1 << e) + 1, e));
    }
};

int n;
vi h, l, r, ans;
stack<par> s;

int main()
{
    while (cin >> n)
    {
        h.resize(n);
        l.resize(n);
        r.resize(n);
        rep(i, n) cin >> h[i];
        SparseTable st(h);

        rep(i, n)
        {
            while(s.empty() == false && s.top().first <= h[i])
                s.pop();
            if (s.empty() == false)
                l[i] = s.top().second;
            if (s.empty() == true)
                l[i] = i;
            s.push({h[i], i});
        }
        while (s.empty() == false)
            s.pop();

        rep(i, n)
        {
            while(s.empty() == false && s.top().first <= h[n - i - 1])
                s.pop();
            if (s.empty() == false)
                r[n - i - 1] = s.top().second;
            if (s.empty() == true)
                r[n - i - 1] = n - i - 1;
            s.push({h[n - i - 1], n - i - 1});
        }
        while (s.empty() == false)
            s.pop();

        rep(i, n)
        {
            int left, right, d;
            if (l[i] == i)
                left = h[i];
            else
                left = h[i] - st.rmq_O1(l[i], i);
            if (r[i] == i)
                right = h[i];
            else
                right = h[i] - st.rmq_O1(i, r[i]);
            d = min(left, right);
        
            if (d >= 150000)
                ans.pb(i + 1);
        }

        rep(i, ans.size())
        {
            if (i != ans.size() - 1)
                cout << ans[i] << ' ';
            else
                cout << ans[i] << '\n';
        }
        ans.clear();

        // debugv(h);
        // debugv(l);
        // debugv(r);
    }
}