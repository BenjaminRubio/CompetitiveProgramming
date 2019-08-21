#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //        \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                      \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int n, m, k, l, r; 
ll v;
vi arr, counter, difs;
graph ops;

int main()
{
    cin >> n >> m >> k;
    arr.assign(n, 0);
    difs.assign(n + 1, 0);
    ops.assign(m, vi(3, 0));
    counter.assign(m + 1, 0);
    rep(i, n)
    {
        cin >> arr[i];
    }
    rep(i, m)
    {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    rep(i, k)
    {
        cin >> l >> r;
        counter[l - 1]++;
        counter[r]--;
    }
    v = 0;
    rep(i, m)
    {
        v += counter[i];
        ll l_, r_, value;
        l_ = ops[i][0];
        r_ = ops[i][1];
        value = ops[i][2];
        difs[l_ - 1] += v * value;
        difs[r_] -= v * value;
    }
    v = 0;
    rep(i, n)
    {
        v += difs[i];
        arr[i] += v;
        cout << arr[i] << ' ';
    }
}