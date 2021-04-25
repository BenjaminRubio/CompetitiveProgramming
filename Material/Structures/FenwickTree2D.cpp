
// 0 - indexed / inclusive - inclusive
template <class T>
class FT2D
{
    vector<vector<T>> t;
    int n, m;

public:
    FT2D() {}
    FT2D(int n, int m) : n(n), m(m) { t.assign(n, vector<T>(m, 0)); }

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
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) +
               sum(r1 - 1, c1 - 1);
    }

    T get(int r, int c) { return sum(r, c, r, c); }

    void set(int r, int c, T value) { add(r, c, -get(r, c) + value); }
};
