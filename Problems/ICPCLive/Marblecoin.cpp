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

struct SuffixArray
{
    int n;
    vector<int> counts, rank, rank_tmp, sa, sa_tmp;
    vector<int> lcp; // optional: only if lcp is needed
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

int n;

int main()
{
    cin >> n;
}