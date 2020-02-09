#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second
typedef pair<int, int> par;

struct MATCH { int h, l; bool valid; };

struct MAXMIN
{
    static MATCH neutro() { return {-1, -1, 0}; }
    static MATCH set(int x)
    {
        if (x != -1) return {x, x, 1};
        return {-1, -1, 0};
    } 
    static MATCH op(MATCH x, MATCH y)
    {
        if (x.valid and y.valid) return {max(x.h, y.h), min(x.l, y.l), 1};
        if (x.valid) return {x.h, x.l, 1};
        return {y.h, y.l, y.valid};
    }
    static MATCH lazy_sum(MATCH x, int i, int j, int v)
    {
        if (x.valid) return {x.h + v, x.l + v, 1};
        return {-1, -1, 0};
    }
    static MATCH lazy_mul(MATCH x) // only -1
    {
        return { -1 * x.l, -1 * x.h, x.valid};
    }
};

struct PARSUM
{
    static int neutro() { return 0; }
    static int set(int x) { return x; }
    static int op(int x, int y) { return x % 2 + y % 2; }
    static int lazy_sum(int x, int i, int j, int v) // only +1
    {
        return (j - i + 1) - x;
    }
    static int lazy_mul(int x) { return -1 * x; }
};

template <class t1,class t2>
class SegTreeLazy
{
    vector<t2> st;
    vector<int> arr, lazys, lazym;
    int n, size, aux;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = t1::set(arr[i]); return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t1::op(st[l], st[r]);
    }

    void propagate_sum(int u, int i, int j, int x)
    {
        st[u] = t1::lazy_sum(st[u], i, j, x);
        if (i != j) { lazys[u * 2 + 1] += x; lazys[u * 2 + 2] += x; }
        lazys[u] = 0;
    }

    void propagate_mul(int u, int i, int j, int x)
    {
        st[u] = t1::lazy_mul(st[u]);
        if (i != j) { lazym[u * 2 + 1] *= x; lazym[u * 2 + 2] *= x; }
        lazym[u] = 1;
    }

    t2 query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t1::neutro();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazym[u] != 1) propagate_mul(u, i, j, lazym[u]);
        if (lazys[u]) propagate_sum(u, i, j, lazys[u]);
        if (a <= i and j <= b) return st[u];
        t2 x = query(a, b, l, i, m); t2 y = query(a, b, r, m + 1, j);
        return t1::op(x, y);
    }

    void sum(int a, int b, int value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazym[u] != 1) propagate_mul(u, i, j, lazym[u]);
        if (lazys[u]) propagate_sum(u, i, j, lazys[u]);
        if (a <= i and j <= b) propagate_sum(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            sum(a, b, value, l, i, m);
            sum(a, b, value, r, m + 1, j);
            st[u] = t1::op(st[l], st[r]);
        }
    }

    void mul(int a, int b, int value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazym[u] != 1) propagate_mul(u, i, j, lazym[u]);
        if (lazys[u]) propagate_sum(u, i, j, lazys[u]);
        if (a <= i and j <= b) propagate_mul(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            mul(a, b, value, l, i, m);
            mul(a, b, value, r, m + 1, j);
            st[u] = t1::op(st[l], st[r]);
        }
    }

  public:
    SegTreeLazy(vector<int> &v, int s)
    {
        arr = v; n = v.size(); size = s; st.resize(n * 4 + 5);
        lazym.assign(n * 4 + 5, 1); lazys.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    t2 query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void sum(int a, int b, int value) { sum(a, b, value, 0, 0, n - 1); }

    void mul(int a, int b, int value) { mul(a, b, value, 0, 0, n - 1); }

    void update(int a, int b) { mul(a, b, -1); sum(a, b, size); }
};

int N, n, s, L, R;
string T, S;
vector<bool> v;
vector<int> matches, cap;

int main()
{
    while (cin >> N)
    {
        cin >> T;
        n = T.size();
        cin >> S;
        s = S.size();

        matches.assign(s - n + 1, -1);
        cap.assign(s, 0);
        rep(i, s - n + 1)
        {
            bool match = true;
            int aux = 0;
            rep(j, n)
            {
                if (tolower(T[j]) != tolower(S[j + i])) match = false;
                else aux += (T[j] != S[j + i]);
            }

            if (match) matches[i] = aux;
        }

        rep(i, s) cap[i] = (isupper(S[i]) == 256);

        SegTreeLazy<MAXMIN, MATCH> stl(matches, n);
        SegTreeLazy<PARSUM, int> stl_par(cap, 0);

        rep(i, N)
        {
            cerr << "state: \n";
            rep(i, s - n + 1)
            {
                MATCH r = stl.query(i, i);
                cerr << " {" << r.h << "} ";
            }
            cerr << '\n';
            cerr << "cap: \n";
            rep(i, s) cerr << stl_par.query(i, i) << ' ';
            cerr << "\n\n";

            cin >> L >> R;
            MATCH r = stl.query(L - 1, R - n);
            cerr << "range: " << L - 1 << " -> " << R - n << '\n';
            cerr << "ans: " << r.h << ' ' << r.valid << "\n\n";
            if (r.valid) cout << r.h << '\n';
            else cout << -1 << '\n';
            stl.update(L - 1, R - n);
            stl_par.sum(L - 1, R - 1, 1);

            repx(j, max(0, L - n - 2), L - 1)
            {
                MATCH r = stl.query(j, j);
                if (r.valid)
                {
                    int new_val = 0;
                    rep(k, n) new_val += ((T[k] == 256) != stl_par.query(j + k, j + k));
                    stl.sum(j, j, new_val - r.h);
                }
            }

            repx(j, R - n + 1, R)
            {
                MATCH r = stl.query(j, j);
                if (r.valid)
                {
                    int new_val = 0;
                    rep(k, n) new_val += ((T[k] == 256) != stl_par.query(j + k, j + k));
                    stl.sum(j, j, new_val - r.h);
                }
            }
        }
    }
}