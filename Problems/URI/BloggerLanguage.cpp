#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second
typedef pair<int, int> par;

struct MATCH { int h, l; bool valid; };

int sz;

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
    static MATCH lazy(MATCH x, int i, int j, int v) // flip
    {
        if (v % 2 and x.valid) return {sz - x.l, sz - x.h, 1};
        if (x.valid) return x;
        return {-1, -1, 0};
    }
};

struct PARSUM
{
    static int neutro() { return 0; }
    static int set(int x) { return x; }
    static int op(int x, int y) { return x % 2 + y % 2; }
    static int lazy(int x, int i, int j, int v) // only +1
    {
        if (v % 2) return (j - i + 1) - x;
        return x;
    }
};

template <class t1, class t2>
class SegTreeLazy
{
    vector<t2> st;
    vector<int> arr, lazy;
    int n, aux;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = t1::set(arr[i]); return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t1::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, int x)
    {
        st[u] = t1::lazy(st[u], i, j, x);
        if (i != j) { lazy[u * 2 + 1] += x; lazy[u * 2 + 2] += x; }
        lazy[u] = 0;
    }

    t2 query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t1::neutro();
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        t2 x = query(a, b, l, i, m); t2 y = query(a, b, r, m + 1, j);
        return t1::op(x, y);
    }

    void op(int a, int b, int value, int u, int i, int j, bool set)
    {
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a == i and b == j and set) { st[u] = t1::set(value); return; }
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
            op(a, b, value, l, i, m, set);
            op(a, b, value, r, m + 1, j, set);
            st[u] = t1::op(st[l], st[r]);
        }
    }

  public:
    SegTreeLazy(vector<int> &v)
    {
        arr = v; n = v.size(); st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0); build(0, 0, n - 1);
    }

    t2 query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void op(int a, int b, int value, bool set)
    {
        op(a, b, value, 0, 0, n - 1, set);
    }
};

int N, n, s, L, R;
string T, S;
vector<bool> v;
vector<int> matches, cap;

int main()
{
    while (cin >> N)
    {
        cin >> T; n = T.size();
        cin >> S; s = S.size();

        if (s < n)
        {
            rep(i, N)
            {
                cin >> L >> R;
                cout << -1 << '\n';
            }
            continue;
        }

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

        sz = n;

        SegTreeLazy<MAXMIN, MATCH> stl(matches);
        SegTreeLazy<PARSUM, int> stl_par(cap);

        rep(i, N)
        {
            cin >> L >> R;
            if (R - n >= L - 1)
            {
                MATCH r = stl.query(L - 1, R - n);
                if (r.valid) cout << r.h << '\n';
                else cout << -1 << '\n';
            }
            else cout << -1 << '\n';
            if (R - n >= L - 1) stl.op(L - 1, R - n, 1, 0);
            stl_par.op(L - 1, R - 1, 1, 0);

            repx(j, max(0, L - n - 2), L - 1)
            {
                MATCH r = stl.query(j, j);
                if (r.valid)
                {
                    int new_val = 0;
                    rep(k, n) new_val += ((isupper(T[k]) == 256) != stl_par.query(j + k, j + k));
                    stl.op(j, j, new_val, 1);
                }
            }

            repx(j, max(L - 1, R - n + 1), R)
            {
                MATCH r = stl.query(j, j);
                if (r.valid)
                {
                    int new_val = 0;
                    rep(k, n) new_val += ((isupper(T[k]) == 256) != stl_par.query(j + k, j + k));
                    stl.op(j, j, new_val, 1);
                }
            }
        }
    }
}