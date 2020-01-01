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
#define invrep(i, b, a) for (int i = b; i >= a; --i)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
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

struct SparseTable
{
    int n;
    vector<ll> memo;
    vector<ll> *arr;
    SparseTable(vector<ll> &_arr)
    {
        arr = &_arr;
        n = arr->size();
        int maxlog = 31 - __builtin_clz(n);
        memo.assign(n * (maxlog + 1), -1);
    }
    ll dp(int i, int e)
    {
        ll &ans = memo[e * n + i];
        if (ans != -1)
            return ans;
        if (e == 0)
            return ans = (*arr)[i];
        return ans = dp(i, e - 1) | dp(i + (1 << (e - 1)), e - 1);
    }
    ll rbq(int l, int r)
    {
        int e = 31 - __builtin_clz(r - l + 1);
        return dp(l, e) | dp(r - (1 << e) + 1, e);
    }
};

struct SuffixArray
{
    int n;
    vector<int> counts, rank, rank_tmp, sa, sa_tmp;
    vector<int> lcp;
    inline int get_rank(int i) { return i < n ? rank[i] : 0; }
    void counting_sort(int maxv, int k)
    {
        counts.assign(maxv + 1, 0);
        rep(i, n) counts[get_rank(i + k)]++;
        repx(i, 1, maxv + 1) counts[i] += counts[i - 1];
        invrep(i, n - 1, 0) sa_tmp[--counts[get_rank(sa[i] + k)]] = sa[i];
        sa.swap(sa_tmp);
    }
    void compute_sa(vector<int> &s)
    {
        rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = rank[sa[0]] = 1;
        repx(i, 1, n) rank[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for (int h = 1; h < n and r < n; h <<= 1)
        {
            counting_sort(r, h);
            counting_sort(r, 0);
            r = rank_tmp[sa[0]] = 1;
            repx(i, 1, n)
            {
                if (rank[sa[i]] != rank[sa[i - 1]] or
                    get_rank(sa[i] + h) != get_rank(sa[i - 1] + h))
                    ++r;
                rank_tmp[sa[i]] = r;
            }
            rank.swap(rank_tmp);
        }
    }

    void compute_lcp(vector<int> &s)
    {
        lcp.assign(n, 0);
        int k = 0;
        rep(i, n)
        {
            int r = rank[i] - 1;
            if (r == n - 1)
            {
                k = 0;
                continue;
            }
            int j = sa[r + 1];
            while (i + k < n and j + k < n and s[i + k] == s[j + k])
                k++;
            lcp[r] = k;
            if (k)
                k--;
        }
    }

    SuffixArray(vector<int> &s)
    {
        n = s.size();
        rank.resize(n);
        rank_tmp.resize(n);
        sa.resize(n);
        sa_tmp.resize(n);
        compute_sa(s);
        compute_lcp(s);
    }
};

int f;
string file;
vector<ll> indexes, indexes_st;
vi s, l, r, sizes, mapping, lcp;
stack<par> aux;
set<ll> subsets;

int main()
{
    while (cin >> f)
    {
        if (f == 0)
            break;

        rep(i, f)
        {
            cin >> file;
            rep(j, file.size()) s.pb(f + 1 + (file[j] - 'a'));
            rep(j, file.size()) sizes.pb(file.size() - j);
            rep(j, file.size() + 1) indexes.pb(1LL << i);
            s.pb(i);
            sizes.pb(0);
        }

        SuffixArray sa(s);
        rep(i, sa.sa.size()) indexes_st.pb(indexes[sa.sa[i]]);
        SparseTable st(indexes_st);
        l.resize(sa.sa.size() + 1);
        r.resize(sa.sa.size() + 1);

        rep(i, sa.lcp.size()) lcp.pb(sa.lcp[i]);

        mapping.resize(lcp.size());
        rep(i, lcp.size())
            mapping[sa.sa[i]] = lcp[i];

        aux.push({-1, f});
        repx(i, f, lcp.size())
        {
            while (aux.top().first >= lcp[i])
                aux.pop();
            l[i] = aux.top().second;
            aux.push({lcp[i], i + 1});
        }
        while (aux.empty() == false)
            aux.pop();

        aux.push({-1, lcp.size()});
        for (int i = lcp.size() - 1; i >= f; i--)
        {
            while (aux.top().first >= lcp[i])
                aux.pop();
            r[i] = aux.top().second;
            aux.push({lcp[i], i});
        }
        while (aux.empty() == false)
            aux.pop();

        repx(i, f, lcp.size()) if (lcp[i])
            subsets.insert(st.rbq(l[i], r[i]));

        repx(i, f, lcp.size())
            if ((i == f || (i > f && lcp[i - 1] < sizes[sa.sa[i]])) && lcp[i] < sizes[sa.sa[i]])
                subsets.insert(indexes_st[i]);
    
        cout << subsets.size() << '\n';
        indexes.clear();
        indexes_st.clear();
        sizes.clear();
        s.clear();
        subsets.clear();
        lcp.clear();
    }
}