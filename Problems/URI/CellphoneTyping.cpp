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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

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

#define debugx(x) // cerr << #x << ": " << x << endl
#define debugv(v)    //     \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)        //                                \
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

struct Trie
{
    graph g;
    vi count;
    int vocab;
    Trie(int vocab) : vocab(vocab)
    {
        g.eb(vocab, -1);
        count.pb(1e9);
    }
    int move_to(int u, int c)
    {
        assert(0 <= c and c < vocab);
        int &v = g[u][c];
        if (v == -1)
        {
            v = g.size();
            g.eb(vocab, -1);
            count.pb(0);
        }
        count[v]++;
        return v;
    }
    void insert(const string &s, char ref = 'a')
    { // insert string
        int u = 0;
        for (char c : s)
            u = move_to(u, c - ref);
    }
    int size() { return g.size(); }
};

int n, u, v, k, mean;
string in;
vector<string> words;

int main()
{
    while (cin >> n)
    {
        Trie t(30);
        rep(i, n)
        {
            cin >> in;
            t.insert(in);
            words.pb(in);
        }

        mean = 0;
        for (auto w : words)
        {
            k = 0;
            u = 0;
            for (char c : w)
            {
                v = t.g[u][c - 'a'];
                if (t.count[u] > t.count[v])
                    k++;
                if (t.count[v] == 1)
                    break;
                u = v;
            }
            mean += k;
        }
        printf("%.2f\n", mean / (float)n);
        words.clear();
    }
}