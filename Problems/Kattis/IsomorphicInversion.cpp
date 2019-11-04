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

const int MAXLEN = 1e6;

struct RH
{
    static const ull B = 131;
    static const ull P = 1e9 + 21;
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
    void init(vector<int> &s)
    {
        for (int x : s)
            assert(x >= 1);
        len = s.size();
        h.resize(len);
        h[0] = s[0];
        repx(i, 1, len) h[i] = add(mul(h[i - 1], B), s[i]);
    }
    RH(string &s, char ref)
    {
        vector<int> tmp;
        for (char c : s)
            tmp.push_back(c - ref + 1);
        init(tmp);
    }
    ull hash(int i, int j)
    {
        if (i == 0)
            return h[j];
        return add(h[j], P - mul(h[i - 1], pow[j - i + 1]));
    }
    ull hash() { return h[len - 1]; }
};
ull RH::pow[MAXLEN];

string s;

int main()
{
    RH::init();

    cin >> s;
    int len = s.size();
    bool impar = (len % 2 == 1);

    RH rh(s, '0');

    int k = 0;
    int i = 0;
    int j = 0;

    while (j <= len / 2 - 1)
    {
        if (rh.hash(i, j) == rh.hash(len - j - 1, len - i - 1))
        {
            k += 2;
            i = j + 1;
        }
        else if (j == len / 2 - 1)
        {
            k++;
            impar = false;
        }
        j++;
    }

    if (impar)
        k++;

    cout << k << '\n';
}