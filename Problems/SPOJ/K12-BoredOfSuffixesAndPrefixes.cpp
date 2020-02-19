#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template <class T>
class FenwickTree2D
{
    vector<vector<T>> t;
    int n, m;

  public:
    FenwickTree2D() {}

    FenwickTree2D(int n, int m)
    {
        t.assign(n, vector<T>(m, 0));
        this->n = n;
        this->m = m;
    }

    void add(int r, int c, T value)
    {
        for (int i = r; i < n; i |= i + 1)
            for (int j = c; j < m; j |= j + 1)
                t[i][j] += value;
    }

    T sum(int r, int c)
    {
        T res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                res += t[i][j];
        return res;
    }

    T sum(int r1, int c1, int r2, int c2)
    {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }

    T get(int r, int c)
    {
        return sum(r, c, r, c);
    }

    void set(int r, int c, T value)
    {
        add(r, c, -get(r, c) + value);
    }
};

int T, N, Q, t, x, y, x_, y_;
char ch;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;

    rep(_, T)
    {
        cin >> N >> Q;

        FenwickTree2D<int> ft2d(N, N);
        rep(i, N) rep(j, N)
        {
            cin >> ch;
            ft2d.set(i, j, ch - 'A' + 1);
        }

        rep(q, Q)
        {
            cin >> t;
            if (t == 0)
            {
                cin >> x >> y >> s;
                if (x == 0) rep(i, N) ft2d.set(y, i, s[i] - 'A' + 1);
                if (x == 1) rep(i, N) ft2d.set(i, y, s[i] - 'A' + 1);
            }
            if (t == 1)
            {
                cin >> x >> y >> x_ >> y_;
                cout << ft2d.sum(x, y, x_, y_) << '\n';
            }
        }
    }
}