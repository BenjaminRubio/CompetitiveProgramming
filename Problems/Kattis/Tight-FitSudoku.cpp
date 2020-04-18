#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int r[6], c[6], g[3][2];

void toggle(int i, int j, int v)
{
    r[i] ^= (1 << v);
    c[j] ^= (1 << v);
    g[i / 2][j / 3] ^= (1 << v);
}

bool check(int i, int j, int v)
{
    return r[i] & (1 << v) || c[j] & (1 << v) || g[i / 2][j / 3] & (1 << v);
}

struct C
{
    int a, b; bool t;
    C() {}
    C(string s, int i, int j)  // creates Cell from input strings
    {
        a = 0, b = 0; t = 0;
        if (s[0] != '-') { a = s[0] - '0'; toggle(i, j, s[0] - '0'); }
        if (s.size() == 3) t = 1;
        if (t and s[2] != '-') { b = s[2] - '0'; toggle(i, j, s[2] - '0'); }
    }
};

C M[6][6];
string temp;

bool solve(int i, int j, bool t)
{
    if (i == 6) return true;

    int i_ = i, j_ = j; bool t_;  // next iteration
    if (!t and M[i][j].t) t_ = 1;
    else if (j < 5) { j_++; t_ = 0; }
    else { i_++; j_ = 0; t_ = 0; }

    int *acc = t ? &M[i][j].b : &M[i][j].a;
    if (*acc) return solve(i_, j_, t_);

    int mn = 1, Mx = 9;  // range of possible numbers
    if (M[i][j].t and t) mn = M[i][j].a + 1;
    if (M[i][j].t and !t) Mx = M[i][j].b ? M[i][j].b - 1: 9;

    repx(v, mn, Mx + 1) if (!check(i, j, v))
    {
        *acc = v;
        toggle(i, j, v);
        if (solve(i_, j_, t_)) return true;
        toggle(i, j, v);
        *acc = 0;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i, 6) rep(j, 6) { cin >> temp; M[i][j] = C(temp, i , j); }

    solve(0, 0, 0);

    rep(i, 6)
    {
        rep(j, 6)
        {
            if (M[i][j].t) cout << M[i][j].a << '/' << M[i][j].b << ' ';
            else cout << M[i][j].a << ' ';
        }
        cout << '\n';
    }
}