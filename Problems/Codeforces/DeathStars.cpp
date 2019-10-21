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

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v) //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)     //                                   \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m)   //                                                                           \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

const int MAXLEN = 1e6;

// ------------------------------------
// rolling hashing using a single prime

struct RH_single
{                                 // rolling hashing
    static const ull B = 127;     // base
    static const ull P = 1e9 + 7; // prime
    static ull pow[MAXLEN];
    static ull add(ull x, ull y) { return (x + y) % P; }
    static ull mul(ull x, ull y) { return (x * y) % P; }
    static void init()
    {
        pow[0] = 1;
        repx(i, 1, MAXLEN) pow[i] = mul(B, pow[i - 1]);
    }
    vector<ull> h;
    int len;
    RH_single(string &s)
    {
        len = s.size();
        h.resize(len);
        h[0] = s[0] - 'a';
        repx(i, 1, len) h[i] = add(mul(h[i - 1], B), s[i] - 'a');
    }
    ull hash(int i, int j)
    {
        if (i == 0)
            return h[j];
        return add(h[j], P - mul(h[i - 1], pow[j - i + 1]));
    }
    ull hash() { return h[len - 1]; }
};
ull RH_single::pow[MAXLEN]; // necessary for the code to compile

int n, m;
vector<string> map1;
vector<vector<string>> map2;
vector<ull> hashmap1;
vector<vector<ull>> hashmap2;
char l;

par search_coordinate()
{
    rep(i, n - m + 1) rep(j, n - m + 1)
    {
        if (hashmap1[i] == hashmap2[0][j])
        {
            bool here = true;
            repx(t, 1, m)
            {
                if (hashmap1[i + t] != hashmap2[t][j])
                {
                    here = false;
                    break;
                }
            }
            if (here)
                return {i + 1, j + 1};
        }
    }
    return {0, 0};
}

int main()
{
    RH_single::init();

    cin >> n >> m;
    map1.resize(n);
    map2.assign(m, vector<string>(n - m + 1, ""));
    hashmap1.resize(n);
    hashmap2.assign(m, vector<ull>(n - m + 1));

    rep(i, n) cin >> map1[i];

    rep(i, m) rep(j, n)
    {
        cin >> l;
        repx(k, max(0, j - m + 1), min(n - m + 1, j + 1))
            map2[i][k] += l;
    }

    rep(i, n)
    {
        string s = map1[i];
        hashmap1[i] = RH_single(s).hash(0, s.size() - 1);
    }

    rep(i, m) rep(j, n - m + 1)
    {
        string s = map2[i][j];
        hashmap2[i][j] = RH_single(s).hash(0, s.size() - 1);
    }

    par coords = search_coordinate();

    cout << coords.first << ' ' << coords.second << '\n';
}
