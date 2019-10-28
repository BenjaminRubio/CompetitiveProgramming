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

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  // cerr << #x << ": " << x << endl
#define debugv(v)  //     \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)   //                                 \
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

const int MAXLEN = 1e5;

vector<string> w;
vi s;
graph o;
int v;

struct RH
{
    static const ull B = 127;
    static const ull P = 1e9 + 7;
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
    RH(string &s)
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
ull RH::pow[MAXLEN];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    RH::init();
    w.resize(3);

    while (cin >> w[0] >> w[1] >> w[2])
    {
        s.assign(3, 0);
        o.assign(3, vi(3, -1));

        rep(i, 3) rep(j, 3)
        {
            if (i != j)
            {
                int s1 = w[i].size();
                int s2 = w[j].size();
                if (s1 > s2)
                    continue;
                else
                {
                    ull h1 = RH(w[i]).hash(0, s1 - 1);
                    auto h = RH(w[j]);
                    rep(k, s2 - s1 + 1)
                    {
                        ull h2 = h.hash(k, k + s1 - 1);
                        if (h1 == h2 && ((s[j] & (1 << i)) == 0))
                        {
                            s[i] |= (1 << j);
                            break;
                        }
                    }
                }
            }
        }
        rep(i, 3) rep(j, 3)
        {
            if (i != j)
            {
                int s1 = w[i].size();
                int s2 = w[j].size();
                if (s[i] == 0)
                {
                    v = 0;
                    o[i][j] = v;
                    auto h1 = RH(w[i]);
                    auto h2 = RH(w[j]);
                    while (v < min(s1, s2))
                    {
                        if (h1.hash(s1 - v - 1, s1 - 1) == h2.hash(0, v))
                            o[i][j] = v + 1;
                        v++;
                    }
                }
            }
        }

        int len = w[0].size() * !bool(s[0]) + w[1].size() * !bool(s[1]) + w[2].size() * !bool(s[2]);
        int sum = len;

        if (bool(s[0]) + bool(s[1]) + bool(s[2]) == 0)
            rep(i, 3) rep(j, 3) rep(k, 3)
                if (i != j && i != k && j != k)
                    sum = min(sum, len - o[i][j] - o[j][k]);
        if (bool(s[0]) + bool(s[1]) + bool(s[2]) == 1)
            rep(i, 3) rep(j, 3)
                if (i != j && !bool(s[i]) && !bool(s[j]))
                    sum = min(sum, len - o[i][j]);

        cout << sum << '\n';
    }
}