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
        return ans = dp(i, e - 1) + dp(i + (1 << (e - 1)), e - 1);
    }

    int rsq(int l, int r)
    {
        int ans = 0;
        int d = r - l + 1;
        for (int e = 0; d; e++, d >>= 1)
        {
            if (d & 1)
            {
                ans += dp(l, e);
                l += 1 << e;
            }
        }
        return ans;
    }
};

int T, n, k;
vi v, st_aux;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> k;
        v.resize(n);
        int sum = 0;

        rep(i, n)
        {
            cin >> v[i];
            sum += v[i];
        }

        st_aux.assign(sum, 0);
        int partial = 0;
        rep(i, n)
        {
            st_aux[(partial % (sum / k)) * k + partial / (sum / k)] = 1;
            partial += v[i];
        }

        // debugv(st_aux);

        SparseTable st(st_aux);
        int ans = 0;
        rep(i, sum / k)
        {
            if (st.rsq(k * i, k * i + k - 1) == k)
                ans++;
        }
        cout << ans << '\n';
    }
}