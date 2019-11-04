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

const int MAXLEN = 5 * 1e5 + 10;

const ull B = 127;
const ull P1 = 1e9 + 7;
const ull P2 = 1e9 + 9;
ull pows1[MAXLEN + 1];
ull add1(ull x, ull y) { return (x + y) % P1; }
ull mul1(ull x, ull y) { return (x * y) % P1; }
ull pows2[MAXLEN + 1];
ull add2(ull x, ull y) { return (x + y) % P2; }
ull mul2(ull x, ull y) { return (x * y) % P2; }

void init()
{
    pows1[0] = 1;
    repx(i, 1, MAXLEN + 1) pows1[i] = mul1(B, pows1[i - 1]);
    pows2[0] = 1;
    repx(i, 1, MAXLEN + 1) pows2[i] = mul2(B, pows2[i - 1]);
}

struct RH1
{
    vector<ull> h;
    int len;

    ull hash(int i, int j)
    {
        return add1(h[i], P1 - mul1(h[j + 1], pows1[j - i + 1]));
    }
    ull hash() { return h[0]; }

    RH1(char *s, int length)
    {
        len = length;
        h.resize(len + 1);
        h[len] = 0;
        for (int i = len - 1; i >= 0; i--)
            h[i] = add1(s[i], mul1(h[i + 1], B));
    }
};

struct RH2
{
    vector<ull> h;
    int len;

    ull hash(int i, int j)
    {
        return add2(h[i], P2 - mul2(h[j + 1], pows2[j - i + 1]));
    }
    ull hash() { return h[0]; }

    RH2(char *s, int length)
    {
        len = length;
        h.resize(len + 1);
        h[len] = 0;
        for (int i = len - 1; i >= 0; i--)
            h[i] = add2(s[i], mul2(h[i + 1], B));
    }
};

int n, r, m;
char chains[10][2000];
vector<ull> chains_h1, chains_h2;
vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', ',', '_'};

int count_binary1(ull x)
{
    int first;
    int last;

    int m;

    int i = 0;
    int j = chains_h1.size();
    while (i < j)
    {
        m = (i + j) >> 1;
        if (chains_h1[m] > x)
            j = m;
        else
            i = m + 1;
    }
    last = i;

    i = 0;
    j = chains_h1.size();
    while (i < j)
    {
        m = (i + j) >> 1;
        if (chains_h1[m] >= x)
            j = m;
        else
            i = m + 1;
    }
    first = i;

    return last - first;
}

int count_binary2(ull x)
{
    int first;
    int last;

    int m;

    int i = 0;
    int j = chains_h2.size();
    while (i < j)
    {
        m = (i + j) >> 1;
        if (chains_h2[m] > x)
            j = m;
        else
            i = m + 1;
    }
    last = i;

    i = 0;
    j = chains_h2.size();
    while (i < j)
    {
        m = (i + j) >> 1;
        if (chains_h2[m] >= x)
            j = m;
        else
            i = m + 1;
    }
    first = i;

    return last - first;
}

int main()
{
    init();

    cin >> n;
    char text[n];
    rep(i, n) cin >> text[i];
    RH1 text_h1(text, n);
    RH2 text_h2(text, n);

    cin >> r >> m;

    rep(i, r)
    {
        rep(j, m) cin >> chains[i][j];
        RH1 aux1(chains[i], m);
        RH2 aux2(chains[i], m);
        chains_h1.pb(aux1.hash());
        chains_h2.pb(aux2.hash());

        rep(j, m) rep(k, 29)
        {
            if (chars[k] == chains[i][j])
                continue;
            chains_h1.pb(add1(aux1.hash(0, j - 1), mul1(pows1[j], add1(chars[k], mul1(B, aux1.hash(j + 1, m - 1))))));
            chains_h2.pb(add2(aux2.hash(0, j - 1), mul2(pows2[j], add2(chars[k], mul2(B, aux2.hash(j + 1, m - 1))))));
        }
    }

    sort(chains_h1.begin(), chains_h1.end());
    sort(chains_h2.begin(), chains_h2.end());

    int ans = 0;
    rep(i, n - m + 1)
    {
        int counts1 = count_binary1(text_h1.hash(i, i + m - 1));
        int counts2 = count_binary2(text_h2.hash(i, i + m - 1));
        // cerr << i << ' ' << counts << ' ' << text_h.hash(i, i + m - 1) << '\n';
        ans += min(counts1, counts2);
    }

    cout << ans << '\n';
}