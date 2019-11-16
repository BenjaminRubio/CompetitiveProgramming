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

const int MAXLEN = 1e6 + 10;

const ull B1 = 127;
const ull P1 = 1e9 + 21;
ull pows1[MAXLEN];
const ull B2 = 127;
const ull P2 = 1e9 + 9;
ull pows2[MAXLEN];
ull add1(ull x, ull y) { return (x + y) % P1; }
ull mul1(ull x, ull y) { return (x * y) % P1; }
ull add2(ull x, ull y) { return (x + y) % P2; }
ull mul2(ull x, ull y) { return (x * y) % P2; }
void init()
{
    pows1[0] = 1;
    repx(i, 1, MAXLEN) pows1[i] = mul1(B1, pows1[i - 1]);
    pows2[0] = 1;
    repx(i, 1, MAXLEN) pows2[i] = mul2(B2, pows2[i - 1]);
}

struct RH1
{
    vector<ull> h;
    int len;
    void init(vector<int> &s)
    {
        for (int x : s)
            assert(x >= 1);
        len = s.size();
        h.resize(len);
        h[0] = s[0];
        repx(i, 1, len) h[i] = add1(mul1(h[i - 1], B1), s[i]);
    }
    RH1(string &s, char ref)
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
        return add1(h[j], P1 - mul1(h[i - 1], pows1[j - i + 1]));
    }
    ull hash() { return h[len - 1]; }
};

struct RH2
{
    vector<ull> h;
    int len;
    void init(vector<int> &s)
    {
        for (int x : s)
            assert(x >= 1);
        len = s.size();
        h.resize(len);
        h[0] = s[0];
        repx(i, 1, len) h[i] = add2(mul2(h[i - 1], B2), s[i]);
    }
    RH2(string &s, char ref)
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
        return add2(h[j], P2 - mul2(h[i - 1], pows2[j - i + 1]));
    }
    ull hash() { return h[len - 1]; }
};

int n;
string s;
set<ull> hashes1, hashes2;
vector<string> texts;

int main()
{
    init();

    vector<RH1> rhs1;
    vector<RH2> rhs2;

    cin >> n;
    rep(i, n)
    {
        cin >> s;
        texts.pb(s);
        RH1 rh1(s, 'a');
        RH2 rh2(s, 'a');
        rhs1.pb(rh1);
        rhs2.pb(rh2);
        hashes1.insert(rh1.hash());
        hashes2.insert(rh2.hash());
    }

    int ans = 0;

    rep(i, n) rep(j, rhs1[i].len)
    {
        int len = rhs1[i].len;
        if (len == 1)
            break;
        
        if (j == 0)
        {
            if (hashes1.count(rhs1[i].hash(1, len - 1)) && hashes2.count(rhs2[i].hash(1, len - 1)))
            {
                cout << texts[i] << '\n';
                ans++;
                break;
            }
        }
        else if (j == len - 1)
        {
            if (hashes1.count(rhs1[i].hash(0, len - 2)) && hashes2.count(rhs2[i].hash(0, len - 2)))
            {
                cout << texts[i] << '\n';
                ans++;
                break;
            }
        }
        else
        {
            if (hashes1.count(add1(mul1(pows1[len - j - 1], rhs1[i].hash(0, j - 1)), rhs1[i].hash(j + 1, len - 1))) && hashes2.count(add2(mul2(pows2[len - j - 1], rhs2[i].hash(0, j - 1)), rhs2[i].hash(j + 1, len - 1))))
            {
                cout << texts[i] << '\n';
                ans++;
                break;
            }
        }
    }

    if (ans == 0)
        cout << "NO TYPOS\n";
}